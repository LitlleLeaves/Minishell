/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:14:47 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/18 13:27:42 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

//parent process waits for all children to finish, and returns the exit status of the last one
static int	ft_wait_all_children(t_data *data, int nmb_of_pipes)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < nmb_of_pipes + 1)
	{
		printf("childs created: %d\n", data->pids[i]);
		i++;
	}
	i = 0;
	while (i < nmb_of_pipes + 1)
	{
		waitpid(data->pids[i], &status, 0);
		printf("child %d exited with status %d\n", data->pids[i], WEXITSTATUS(status));
		i++;
	}
	return (status);
}

//fork a proces for each command
int	ft_fork_process(t_token *head, t_data *data, int nmb_of_pipes)
{
	int i;

	i = 0;
	while (i < nmb_of_pipes + 1)
	{
		data->pids[i] = fork();
		if (data->pids[i] < 0)
			return (-1);
		else if (data->pids[i] == 0)
		{
			ft_setup_pipes(data, nmb_of_pipes, i);
			if (ft_child_process(head, data, nmb_of_pipes, i) < 0)
				exit(EXIT_FAILURE);
			exit(EXIT_SUCCESS);
		}
		else
			i++;
	}
	return (1);
}
//parent process sets up pipes and pids,check for single builtin and executes it or then forks the children, and waits for them to finish
int ft_start_exec(t_token *head, char **envp)
{
	int		nmb_of_pipes;
	t_data	data;

	data.envp = envp;
	nmb_of_pipes = ft_find_pipes(head);
	if (ft_check_builtins_before_fork(head, &data) > 0 && nmb_of_pipes == 0)
		return (ft_single_builtin(head, &data));
	if (ft_create_pipes_and_pids(nmb_of_pipes, &data) < 0)
		return (ft_free_tokens(head),-2);
	if (ft_fork_process(head, &data, nmb_of_pipes) < 0)
		return (ft_free_tokens(head), ft_close_all_pipes(&data, nmb_of_pipes),- 3);
	ft_close_all_pipes(&data, nmb_of_pipes);
	ft_wait_all_children(&data, nmb_of_pipes);
	
	return (ft_cleanup(head, &data, nmb_of_pipes), 1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_token *head;
	
	head = ft_get_head();
	if (ft_start_exec(head, envp) < 0)
		return (-1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:14:47 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/10 12:53:48 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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
			ft_child_process(head, data, nmb_of_pipes, i);
		i++;
	}
	return (1);
}

int ft_start_exec(t_token *head)
{
	int		nmb_of_pipes;
	t_data	*data;

	if (nmb_of_pipes = ft_find_pipes(head) < 0)
		return (-1);
	if (ft_create_pipes_and_pids(nmb_of_pipes, data) < 0)
		return (-2);
	
	
}

int	main(int argc, char *argv[], char *envp[])
{
	t_token *head;
	
	head = ft_get_head();
	if (ft_start_exec(head) < 0)
		return (-1); //TODO cleanup
	return (0);
}
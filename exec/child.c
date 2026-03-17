/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:53:09 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/17 13:57:08 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <errno.h>

//handle execution failure, free arguments and exit with status 127
void ft_execution_failure(char *executable, char **arguments)
{
	free(arguments);
	ft_free_arr((void **)arguments);
	exit(127);
}

//find path in envp and build the argument list, then find executable path and execute
int ft_child_execute(t_exec_info *exec_info, t_data *data)
{
	char	**arguments;
	char	*executable;

	if (exec_info->fd_in >= 0)
    {
        dup2(exec_info->fd_in, STDIN_FILENO);
        close(exec_info->fd_in);
    }
	if (exec_info->fd_out >= 0)
    {
        dup2(exec_info->fd_out, STDOUT_FILENO);
        close(exec_info->fd_out);
    }
	arguments = ft_split(exec_info->str, ' ');
	if (arguments == NULL || arguments[0] == NULL)
		exit(EXIT_FAILURE);
	if (ft_strchr(arguments[0], '/') == NULL)
		executable = ft_make_executable(arguments[0], data->envp);
	else
		executable = ft_relative_executable(arguments[0]);
	if (executable == NULL)
		exit(127);
	execve(executable, arguments, data->envp);
	ft_execution_failure(executable, arguments);
	return (-1);
}

//start execution of the command
int	ft_child_start_execute(t_exec_info *exec_info ,t_data *data, int i)
{
	t_token *curr;
	char	*str;

	exec_info->fd_in = -2;
	exec_info->fd_out = -2;
	exec_info->command_number = i;
	curr = exec_info->start;
	str = NULL;
	while (curr != exec_info->end && curr != NULL)
	{
		if (ft_apply_redirection(&exec_info->fd_in, &exec_info->fd_out, \
curr, &exec_info->str) < 0)
			return (-1);
		curr = curr->next;
	}
	if (exec_info->str != NULL)
	{
		ft_child_execute(exec_info, data);
	}
	return (1);
}
//find start and end of command
int ft_find_start_end(int i, t_exec_info *exec_info, t_token *head)
{
	int	counter;
	t_token	*start;
	t_token	*end;

	counter = 0;
	start = head;
	while (counter < i && (start != NULL))
	{
		if (start->type == PIPE)
			counter++;
		start = start->next;
	}
	if (start == NULL)
		return (-1);
	end = start;
	while ((end != NULL) && end->type != PIPE)
		end = end->next;
	exec_info->start = start;
	exec_info->end = end;
	fprintf(stderr, "command %d: start: %s, end: %s\n", i, exec_info->start->value, exec_info->end ? exec_info->end->value : "NULL");
	return (1);
}

//child process finds the start and end of its command, applies redirections, and executes the command
int	ft_child_process(t_token *head, t_data *data, int nmb_of_pipes, int i)
{
	t_exec_info exec_info;

	if (ft_find_start_end(i, &exec_info, head) < 0)
		return (-1);
	if (ft_child_start_execute(&exec_info ,data, i) < 0)
		return (-2);
	return (1);
}

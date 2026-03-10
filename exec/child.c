/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:53:09 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/10 15:26:18 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <errno.h>

int ft_handle_in(int *fd_in, t_token *curr)
{
	if (*fd_in >= 0)
		close(*fd_in);
	*fd_in = open(curr->value, O_RDONLY, 0644);
	if (*fd_in == -1)
			printf("Minishell: %s: %s\n", curr->value, strerror(errno));
	return (*fd_in);
}
int ft_handle_in_heredoc(int *fd_in, t_token *curr)
{
	//TODO heredoc implemntation
	return (1);
}
int ft_handle_out_app(int *fd_out, t_token *curr)
{
	if (*fd_out >= 0)
		close(*fd_out);
	*fd_out = open(curr->value, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (*fd_out == -1)
	{
		printf("Minishell %s: %s\n", curr->value, strerror(errno));
	}
	return (*fd_out);
}
int ft_handle_out_trunc(int *fd_out, t_token *curr)
{
		if (*fd_out >= 0)
		close(*fd_out);
	*fd_out = open(curr->value, O_WRONLY| O_TRUNC | O_CREAT, 0644);
	if (*fd_out == -1)
	{
		printf("Minishell: %s: %s\n", curr->value, strerror(errno));
	}
	return (*fd_out);
}

//handle redirection
int ft_apply_redirection(int *fd_in, int *fd_out, t_token *curr, char *str)
{
	if (curr->type == REDIR_IN)
		ft_handle_in(fd_in, curr);
	else if (curr->type == HEREDOC)
		ft_handle_in_heredoc(fd_in, curr);
	else if (curr->type == REDIR_OUT_APPEND)
		ft_handle_out_app(fd_out, curr);
	else if (curr->type == REDIR_OUT_TRUNCT)
		ft_handle_out_trunc(fd_out, curr);
	else if (curr->type == WORD)
		str = curr->value;
	if (*fd_in == -1 || *fd_out == -1)
		return (-1);
	return(1);
}
//start execution of the command
int	ft_child_execute(t_token *start, t_token *end, t_data *data, int i)
{
	int fd_in;
	int	fd_out;
	t_token *curr;
	char	*str;

	fd_in = -2;
	fd_out = -2;
	curr = start;
	str = NULL;
	while (curr != end && curr != NULL)
	{
		if (ft_apply_redirection(&fd_in, &fd_out, curr, str) < 0)
			return (-1);
		curr = curr->next;
	}
}

//find start and end of command and its redirections
int	ft_child_process(t_token *head, t_data *data, int nmb_of_pipes, int i)
{
	int	counter;
	t_token	*start;
	t_token	*end;

	counter = 0;
	start = head;
	while (counter < i && (start =! NULL))
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
	ft_child_execute(start, end, data, i);
	return (1);
}
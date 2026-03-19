/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:04:50 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/19 13:33:13 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <errno.h>

//infile regular
int ft_handle_in(int *fd_in, t_token *curr)
{
	if (*fd_in >= 0)
		close(*fd_in);
	*fd_in = open(curr->value, O_RDONLY, 0644);
	if (*fd_in == -1)
	{
		printf("Minishell: %s: %s\n", curr->value, strerror(errno));
		exit(1);	
	}
	return (*fd_in);
}

//infile heredoc
int ft_handle_in_heredoc(int *fd_in, t_token *curr)
{
	//TODO heredoc implemntation
	return (1);
}

//outfile append
int ft_handle_out_app(int *fd_out, t_token *curr)
{
	if (*fd_out >= 0)
		close(*fd_out);
	*fd_out = open(curr->value, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (*fd_out == -1)
	{
		printf("Minishell %s: %s\n", curr->value, strerror(errno));
		exit(1);
	}
	return (*fd_out);
}

//outfile trucation
int ft_handle_out_trunc(int *fd_out, t_token *curr)
{
		if (*fd_out >= 0)
		close(*fd_out);
	*fd_out = open(curr->value, O_WRONLY| O_TRUNC | O_CREAT, 0644);
	if (*fd_out == -1)
	{
		printf("Minishell: %s: %s\n", curr->value, strerror(errno));
		exit(1);
	}
	return (*fd_out);
}

//handle redirection and save command
int ft_apply_redirection(int *fd_in, int *fd_out, t_token *curr)
{
	if (curr->type == REDIR_IN)
		ft_handle_in(fd_in, curr);
	else if (curr->type == HEREDOC) //TODO
		ft_handle_in_heredoc(fd_in, curr);
	else if (curr->type == REDIR_OUT_APPEND)
		ft_handle_out_app(fd_out, curr);
	else if (curr->type == REDIR_OUT_TRUNCT)
		ft_handle_out_trunc(fd_out, curr);
	if (*fd_in == -1 || *fd_out == -1)
		return (-1);
	return(1);
}
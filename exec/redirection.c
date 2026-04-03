/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:04:50 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/03 16:58:36 by jjhurry          ###   ########.fr       */
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
		 printf("minishell: %s: %s\n", curr->value, strerror(errno));
    	return (-1); 
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
		printf("minishell: %s: %s\n", curr->value, strerror(errno));
    	return (-1); // ✅ let caller decide what to do
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
		 printf("minishell: %s: %s\n", curr->value, strerror(errno));
    	return (-1); // ✅ let caller decide what to do
	}
	return (*fd_out);
}

//handle redirection and save command
int ft_apply_redirection(int *fd_in, int *fd_out, t_token *curr)
{
	if (curr->type == REDIR_IN)
        return (ft_handle_in(fd_in, curr));
    else if (curr->type == HEREDOC)
        return (ft_handle_in_heredoc(fd_in, curr));
    else if (curr->type == REDIR_OUT_APPEND)
        return (ft_handle_out_app(fd_out, curr));
    else if (curr->type == REDIR_OUT_TRUNCT)
        return (ft_handle_out_trunc(fd_out, curr));
    return (1);
}
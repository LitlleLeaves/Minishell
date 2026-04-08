/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:53:13 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/08 17:27:37 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int ft_heredoc_parsing(t_token *curr)
{
	static int	counter;
	char		*file;
	char		*line;
	char		*tmp;

	if (counter == NULL)
		counter = 0;
	else
		counter++;
	file = ft_strjoin("~/tmp/heredoc", ft_itoa(counter));
	curr->heredoc_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while(1)
	{
		line = readline("> ");
		if (line == NULL || ft_strcmp(line, curr->value) == 0)
			break;
		if (curr->type == HEREDOC_EXPANSION)
		{
			//TODO parse line voor expansions
		}
		write(curr->heredoc_fd, line, ft_strlen(line));
    	write(curr->heredoc_fd, "\n", 1);
    	free(line);
	}
}

void handle_heredoc(t_token *head)
{
	t_token	*curr;

	curr = head;
	while (curr != NULL)
	{
		if (curr->type == HEREDOC_EXPANSION || HEREDOC_NO_EXPANSION)
			if (ft_heredoc_parsing(curr) < 0)
				return (-1);
		curr = curr->next;
	}
}

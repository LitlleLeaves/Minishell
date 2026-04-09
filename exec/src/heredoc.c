/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:53:13 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/09 13:13:12 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int ft_heredoc_create_file(t_token *curr, t_data *data)
{
	static int	counter;
	char		*tmp;
	char		*tmp2;
	char		*file;

	counter++;
	tmp = ft_itoa(&data);
	tmp2 = ft_itoa(counter);
	if (tmp == NULL || tmp2 == NULL)
		return (-1);
	file = ft_strjoin("~/tmp/heredoc", tmp);
	free(tmp);
	if (file  == NULL)
		return (-2);
	tmp = file;
	file = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	if (file == NULL)
		return (-3);
	curr->heredoc_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(file);
	if (curr->heredoc_fd == -1)
		return (-4);
	return (1);
}

int ft_heredoc_expansion(char *line)
{
	
}

int ft_heredoc_parsing(t_token *curr, t_data *data)
{
	char		*line;

	if (ft_heredoc_create_file < 0)
		return (-1);
	while(1)
	{
		line = readline("> ");
		if (line == NULL || ft_strcmp(line, curr->value) == 0)
			break;
		if (curr->type == HEREDOC_EXPANSION)
		{
			line = ft_heredoc_expansion(line);
			if (line == NULL)
				return (-1);
		}
		write(curr->heredoc_fd, line, ft_strlen(line));
    	write(curr->heredoc_fd, "\n", 1);
    	free(line);
	}
}

int handle_heredoc(t_token *head, t_data *data)
{
	t_token	*curr;

	curr = head;
	while (curr != NULL)
	{
		if (curr->type == HEREDOC_EXPANSION || HEREDOC_NO_EXPANSION)
			if (ft_heredoc_parsing(curr, data) < 0)
				return (-1);
		curr = curr->next;
	}
}

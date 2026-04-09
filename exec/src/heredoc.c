/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:53:13 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/09 15:20:52 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdint.h>
#include <stdio.h>

int ft_heredoc_create_file(t_token *curr, t_data *data)
{
	static int	counter;
	char		*tmp;
	char		*tmp2;
	char		*file;

	counter++;
	tmp = ft_itoa((int)(uintptr_t)data);
	tmp2 = ft_itoa(counter);
	if (tmp == NULL || tmp2 == NULL)
		return (-1);
	file = ft_strjoin("/tmp/heredoc", tmp);
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

char *ft_heredoc_replace_line(char *line, char *key, char *value, int start)
{
	int		i;
	int		len;
	char	*new_line;
	int		val_len;
	int		val_index;
	
	i = 0;
	val_len = ft_strlen(value);
	len = ft_strlen(line) - ft_strlen(key) - 1 + val_len + 1;
	new_line = ft_calloc(len, sizeof(char));
	if (new_line == NULL)
		return (NULL);
	while (i < start)
	{
		new_line[i] = line[i];
		i++;
	}
	val_index = 0;
	while (i < start + val_len + 1)
		new_line[i++] = value[val_index++];
	while (i < len)
	{
		new_line[i] = line[i + val_len - ft_strlen(key)];
		i++;
	}
	return(free(line), new_line);
}

int ft_heredoc_expansion(char *line, t_data *data)
{
	int		i;
	int		key_len;
	int		var_len;
	char	*key;
	char	*value;

	i = 0;
	while (line[i] != '\0')
	{
		key_len = 0;
		if (line[i] == '$')
		{
			i++;
			if (line[i] != '_' || ft_isalpha(line[i]) != 1)
				continue;
			while(ft_isalnum(line[i + key_len]) == 1 || line[i + key_len] == '_')
				key_len++;	
			key = ft_substr(line, i + 1, key_len);
			value = ft_getenv(data, key);
			if (key == NULL || value == NULL)
				return (-1);
			line = ft_heredoc_replace_line(line, key, value, i);
		}
		free(key);
		if (line[i] != '$')
			i++;
	}
}


int ft_heredoc_parsing(t_token *curr, t_data *data)
{
	char		*line;

	if (ft_heredoc_create_file(curr, data) < 0)
		return (-1);
	while(1)
	{
		line = readline("> ");
		if (line == NULL || ft_strcmp(line, curr->value) == 0)
			break;
		if (curr->type == HEREDOC_EXPANSION)
		{
			if (ft_strchr(line, '$') != NULL)
				line = ft_heredoc_expansion(line, data);
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
		if (curr->type == HEREDOC_EXPANSION || curr->type == HEREDOC_NO_EXPANSION)
			if (ft_heredoc_parsing(curr, data) < 0)
				return (-1);
		curr = curr->next;
	}
}


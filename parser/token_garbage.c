/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_garbage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:17:09 by side-lan          #+#    #+#             */
/*   Updated: 2026/03/19 19:24:05 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*tokenize_input(char *str)
{
	t_token *head;
	t_token	*current;
	int		index;
	int		start;

	current = NULL;
	index = 0;
	while (str[index] != '\0')
	{
		start = index;
		if (current == NULL)
		{
			current = classify_and_make(str + start);
			head = current;
		}
		else
		{
			current->next = classify_and_make(str + start);
			current = current->next;
		}
		if (check_delimeters(str[index]) == 0)
		{
			while (check_delimeters(str[index] == 0))
				index++;
		}
		while (check_delimeters(str[index]) == 1 && str[index] != '\0')
			index++;
	}
	return (head);
}

// < infile< infile2.txt < infile3 wc <infile4 -l |  wc -l  | wc -l > outfile
t_token	*classify_and_make(char *line)
{
	t_token	*token;
	int		index;

	index = 0;
	while (line[index] == ' ')
		index++;
	if (check_delimeters(line[index]) == 0) //command
	{
		token = if_word(index, line);
		return (token);
	}
	else if (line[index] == '|') //pipe
	{
		token = make_new_token(NULL, PIPE);
		return (token);
	}
 	else if (line[index] == '>' && line[index + 1] == '>') //append
	{
		token = if_redirection(index, line, REDIR_OUT_APP);
		return (token);
	}
 	else if (line[index] == '<' && line[index + 1] == '<') // heredeoc
	{
		token = if_redirection(index, line, HEREDOC);
		return (token);
	}
 	else if (line[index] == '>') // truncate
	{
		token = if_redirection(index, line, REDIR_OUT_TRUNC);
		return (token);
	}
 	else if (line[index] == '<') // input
	{
		token = if_redirection(index, line, REDIR_IN);
		return (token);
	}
	return (NULL);
}

int		check_delimeters(char c)
{
	if (c == '|' && c == '>' && c == '<' && c == ' ')
		return (1);
	return (0);
}

char	*get_line(void)
{
	char	*line;
	char	*temp;
	int		read_return;

	read_return = 0;
	line = ft_strdup("");
	temp = malloc(1024 * sizeof(char));
	if (!temp)
		return (printf("malloc fail"), NULL);
	while (temp != NULL)
	{
		read_return	= read(0, line, 1024);
		printf("%d\n", read_return);
		if (read_return == -1)
			return (printf("read error"), NULL);
		line[read_return] = '\0';
		line = ft_strjoin(line, temp);
		free(temp);
		if (!line)
			return (printf("join error"), NULL);
	}
	return (line);
}


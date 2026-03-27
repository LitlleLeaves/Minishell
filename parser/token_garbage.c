/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_garbage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:17:09 by side-lan          #+#    #+#             */
/*   Updated: 2026/03/27 21:41:48 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//int		index_over_command(char *line, int index)
//{
//	//printf("before comand index:%d\n", index);
//	while (line[index] != '\0' && check_delimeters(line[index]) == 0)
//		index++;
//	return (index);
//}

int		index_to_next_delimetre(char *line, int index)
{
	while (line[index] == ' ')
		index++;
	if (line[index] == '<' || line[index] == '>')
	{
		while (check_delimeters(line[index]) == 1)
			index++;
		while (check_delimeters(line[index]) == 0)
			index++;
	}
	else if (line[index] == '|')
		index++;
	else
	{
		while (check_delimeters(line[index]) == 0)
			index++;
	}
	return (index);
}

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
		//make the token
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
		//index towards new token
		//if (check_delimeters(str[index]) == 0)
		//	index = index_over_command(str, index);
		//else
		index = index_to_next_delimetre(str, index);
		//printf("token value%s\n", current->value);
		//printf("index:%d\n", index);
		//printf("%c, %s\n", str[index] ,ft_substr(str, start, index - start));
	}
	return (head);
}

//< infile< infile2.txt < infile3 wc <infile4 -l |  wc -l  | wc -l > outfile
t_token	*classify_and_make(char *line)
{
	t_token	*token;
	int		index;

	index = 0;
	while (line[index] == ' ')
		index++;
	//printf("index%d\n", index);
	//printf("on:%c\n", line[index]);
	if (check_delimeters(line[index]) == 0) //command
	{
		token = if_word(index, line);
		return (token);
	}
	else if (line[index] == '|') //pipe
	{
		token = make_new_token("|", PIPE);
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

char	*get_line(void)
{
	char	*line;

	line = readline("you are a cog>");
	if (!line)
		return (NULL);
	return (line);
}

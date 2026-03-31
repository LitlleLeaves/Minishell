/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_garbage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:17:09 by side-lan          #+#    #+#             */
/*   Updated: 2026/03/31 17:40:49 by side-lan         ###   ########.fr       */
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

int		index_to_next_delimeter(char *line, int index)
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
	if (line[index] == '\'' || line[index] == '"')
		index = if_index_finds_quotations(line, index);
	else if (line[index] == '|')
		index++;
	else
	{
		while (check_delimeters(line[index]) == 0)
			index++;
	}
	return (index);
}

int if_index_finds_quotations(char *line, int index)
{
    char	quote_type;

    quote_type = line[index];
    index++;
    while (line[index] != '\0' && line[index] != quote_type)
        index++;
    if (line[index] == quote_type)
        index++;
    else
    {
        printf("minishell: syntax error: unclosed quote\n");
    }
    return (index);
}

//echo 'hello     world'
//echo "My home is $HOME" and 'My home is $HOME'
//echo "It's a 'beautiful' day"
//ls "" "-l"
//echo 'Wait'"...""$USER"'!'

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
		index = index_to_next_delimeter(str, index);
	}
	return (head);
}

//< infile< infile2.txt < infile3 wc <"infile4 " -l |  wc -l  | wc -l > outfile
t_token	*classify_and_make(char *line)
{
	int		index;

	index = 0;
	while (line[index] == ' ')
		index++;
	//printf("index%d\n", index);
	//printf("on:%c\n", line[index]);
	if (check_delimeters(line[index]) == 0) //command
		return (if_word(index, line));
	else if (line[index] == '|') //pipe
		return (make_new_token("|", PIPE));
 	else if (line[index] == '>' && line[index + 1] == '>') //append
		return (if_redirection(index, line, REDIR_OUT_APP));
 	else if (line[index] == '<' && line[index + 1] == '<') // heredeoc
		return (if_redirection(index, line, HEREDOC));
 	else if (line[index] == '>') // truncate
		return (if_redirection(index, line, REDIR_OUT_TRUNC));
 	else if (line[index] == '<') // input
		return (if_redirection(index, line, REDIR_IN));
	return (NULL);
}

char	*get_line(void)
{
	char	*line;

	line = readline("you are a cog>");
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

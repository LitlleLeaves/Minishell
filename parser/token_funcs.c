/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:36:59 by side-lan          #+#    #+#             */
/*   Updated: 2026/03/27 21:40:41 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*make_new_token(char *value, t_token_type type)
{
	t_token	*token;
	char	*temp;

	token = malloc(sizeof(t_token) * 1);
	if (!token)
		return (printf("malloc error"), NULL);
	temp = strdup(value);
	if (!temp)
		return (printf("value error"), NULL);
	token->value = temp;
	token->type = type;
	token->next = NULL;
	return (token);	
}

//t_token	*if_pipe(char *line)
//{
//	char 	*value;
//	t_token	*token;
	
//	value = ft_strdup("|");
//	if (!value)
//		return (printf("strdup error"), NULL);
//	token = make_new_token(value, PIPE);
//	return (token);
//}
int		check_delimeters(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == ' ' || c == '\0')
		return (1);
	return (0);
}
// wc -l | wc -l
t_token	*if_word(int start, char *line)
{	
	t_token	*token;
	int		index;
	char	*value;

	index = 0;
	while (check_delimeters(line[index + start]) == 0 && line[index + start] != '\0')
		index++;
	value = ft_substr(line, start, index);
	if (!value)
		return (printf("substr error"), NULL);
	token = make_new_token(value, COMMAND);
	free(value);
	return (token);
}

t_token *if_redirection(int start, char *line, t_token_type type)
{
	int		index;
	char 	*value;
	t_token	*token;
	
	index = 0;
	while (check_delimeters(line[start]) == 1)
	{
		start++;
		if (line[start] == '\0')
			return (printf("huh??"), NULL);
	}
	while (check_delimeters(line[start + index]) == 0 && line[index + start] != '\0')
		index++;
	value = ft_substr(line, start, index);
	if (!value)
		return (NULL);
	token = make_new_token(value, type);
	return (token);
}

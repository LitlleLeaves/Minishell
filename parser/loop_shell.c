/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:30:48 by side-lan          #+#    #+#             */
/*   Updated: 2026/04/04 16:19:20 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
static char	*stringify_enum(t_token_type token);

int	main(int argc, char *argv[], char *envp[])
{
	argc = 0;
	argv[0] = 0;
	main_loop();
	return (0);
}
//main loop of te shell
int		main_loop(void)
{
	char	*line;
	t_token	*head;
	t_token	*token;

	while (1)
	{
		line = get_line();
		if (line && *line)
		{
            add_history(line);
			head = tokenize_input(line);
			token = head;
			printf("woopwooop\n");
			while (token != NULL)
			{
				if (token->value == NULL)
					token = token->next;
				printf("%s %s\n", token->value, stringify_enum(token->type));
				token = token->next;
			}
			while (head != NULL)
			{
				token = head;
				head = head->next;
				free(token->value);
				free(token);
			}
		}
		//printf("%s\n", line);
	}
	rl_clear_history();	
	return (0);
}

static char	*stringify_enum(t_token_type token)
{
	if (token == WORD)
		return ("command");
	if (token == PIPE)
		return ("PIPE");
	if (token == REDIR_OUT_APP)
		return ("REDIR_OUT_APP");
	if (token == REDIR_OUT_TRUNC)
		return ("REDIR_OUT_TRUNC");
	if (token == REDIR_IN)
		return ("REDIR_IN");
	if (token == HEREDOC)
		return ("HEREDOC");
	return (NULL);
}
//char	*parse(char *line)
//{
//	int	counter;

//}
//int	main(void)
//{
//	char	str[7] = " wc -l";
//	t_token *token;
//	t_token	*head;

//	head = tokenize_input(str);
//	token = head;
//	while (token != NULL)
//	{
//		printf("%s\n", token->value );
//		token = token->next;
//	}
//	while (head != NULL)
//	{
//		token = head;
//		head = head->next;
//		free(token->value);
//		free(token);
//	}
//	return (0);
//}
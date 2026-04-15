/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:30:48 by side-lan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/15 15:07:34 by side-lan         ###   ########.fr       */
=======
/*   Updated: 2026/04/14 14:24:11 by side-lan         ###   ########.fr       */
>>>>>>> 843164a (pushy)
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
static char	*stringify_enum(t_token_type token);
static void	print_tokenized_list(t_data	*data);

int	main(int argc, char *argv[], char *envp[])
{
	argc = 0;
	argv[0] = 0;
	main_loop(envp);
	return (0);
}

//main loop of te shell
int		main_loop(char	*envp[])
{
	t_data	data;

	data.current = NULL;
	data.head = NULL;
	data.line = NULL;
	if (ft_copy_envp(&data, envp) == -1)
		return (printf("error"));
	while (1)
	{
		data.line = get_line();
		//printf("%s\n", data.line);
		if (data.line && *data.line)
		{
			add_history(data.line);
<<<<<<< HEAD
			check_expansions(&data, &data.line);
=======
			check_expansions(&data);
>>>>>>> 843164a (pushy)
			if (data.line == NULL)
				break ;
			data.head = tokenize_input(&data, data.line);
			data.current = data.head;
			//printf("woopwooop\n");
			print_tokenized_list(&data);
		}
		//printf("%s\n", data.line);
	}
	rl_clear_history();	
	return (0);
}

static void	print_tokenized_list(t_data	*data)
{
	while (data->current != NULL)
	{
		if (data->current->value == NULL)
			data->current = data->current->next;
		printf("%s %s\n", data->current->value, stringify_enum(data->current->type));
		data->current = data->current->next;
	}
	while (data->head != NULL)
	{
		data->current = data->head;
		data->head = data->head->next;
		free(data->current->value);
		free(data->current);
	}
}

static char	*stringify_enum(t_token_type token)
{
	if (token == WORD)
		return ("WORD");
	if (token == PIPE)
		return ("PIPE");
	if (token == REDIR_OUT_APP)
		return ("REDIR_OUT_APP");
	if (token == REDIR_OUT_TRUNC)
		return ("REDIR_OUT_TRUNC");
	if (token == REDIR_IN)
		return ("REDIR_IN");
<<<<<<< HEAD
	if (token == HEREDOC_EXPANSION)
		return ("HEREDOC_EXPANSION");
	if (token == HEREDOC_NO_EXPANSION)
		return ("HEREDOC_NO_EXPANSION");
=======
	if (token == HEREDOC)
		return ("HEREDOC");
	if (token == HEREDOC_QUOTES)
		return ("HEREDOC_QUOTES");
>>>>>>> 843164a (pushy)
	return (NULL);
}

int ft_copy_envp(t_data *data, char **envp)
{
    int i = 0;

    while (envp[i] != NULL)
        i++;
    data->envp = ft_calloc(i + 1, sizeof(char *));
    if (data->envp == NULL)
        return (-1);
    int j = 0;
    while (j < i)
    {
        data->envp[j] = ft_strdup(envp[j]);
        if (!data->envp[j])
            return (-1);
        j++;
    }
    return (1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > INT_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

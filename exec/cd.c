/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:27:13 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/30 16:53:37 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <errno.h>

void ft_cd_no_arguments()
{
	char *home;
	
	home = getenv("HOME");
	if (chdir(home) == -1)
		printf("minishell: %s", strerror(errno));
}

void ft_cd_helper(t_token **curr)
{
	int	count;

	count = 0;
	while (curr != NULL)
	{
		if ((*curr)->type == WORD)
			count++;
		if (count == 2)
			break;
		*curr = (*curr)->next;
	}
}

void ft_cd_one_argument(t_token *head, int words)
{
	t_token	*curr;
	char	*path;
	char	*home;
	
	curr = head;
	ft_cd_helper(&curr);
	path = curr->value;
	if (ft_strncmp(curr->value, "~", 1) == 0)
	{
		// printf("~ detected\n");
		home = getenv("HOME");
		// printf("%s\n", home);
		if (curr->value[1] != '\0')
			path = ft_strjoin(home, curr->value + 1);
		else
			path = ft_strdup(home);
		if (path  == NULL)
			return;
		if (chdir(path) == -1)
			printf("minishell: %s", strerror(errno));
		free(path);
	}
	// printf("%s", curr->value);
	else if (chdir(path) == -1)
		printf("minishell: %s", strerror(errno));
}

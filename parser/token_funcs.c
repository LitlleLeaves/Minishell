/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:36:59 by side-lan          #+#    #+#             */
/*   Updated: 2026/03/18 21:20:42 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*make_new_token(int fd, char *value, t_token_type type)
{
	t_token	*token;
	char	*temp;

	token = malloc(sizeof(t_token) * 1);
	if (!token)
		return (printf("malloc error"), 0);
	temp = ft_substr(value);
	if (!temp)
		return (printf("value error"), 0);
	token->value = temp;
	token->fd = fd;
	token->type = type;
	token->next = NULL;
	return (token);	
}



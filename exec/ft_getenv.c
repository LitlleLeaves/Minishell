/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:55:38 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/31 13:03:51 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char *ft_getenv(t_data *data, char *var)
{
	int i;
	size_t len;

	i = 0;
	len = ft_strlen(var);
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], var, len) == 0\
&& data->envp[i][len] == '=')
			return (data->envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

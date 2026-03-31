/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:55:38 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/31 13:47:06 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char *ft_getenv(t_data *data, char *var)
{
	int i;
	size_t len;

	i = 0;
	len = ft_strlen(var);
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], var, len) == 0\
&& data->envp[i][len] == '=')
			return (data->envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

int ft_extend_env(t_data *data, char *entry)
{
	int i;
	char **new_list;

	i = 0;
	while (data->envp[i] != NULL)
		i++;
	new_list = ft_calloc(i + 2 , sizeof(char *));
	if (new_list == NULL)
		return (-1);
	i = 0;
	while (data->envp[i] != NULL)
	{
		new_list[i] = ft_strdup(data->envp[i]);
		if (new_list[i] == NULL)
			return (free(new_list), -2);
		free(data->envp[i]);
		i++;
	}
	new_list[i] = entry;
	free(data->envp);
	data->envp = new_list;
	return (1);
}

int ft_change_env(char *key, char *value, t_data *data)
{
	int i;
	int len;
	char *entry;

	i = 0;
	len = ft_strlen(key) + ft_strlen(value) + 2;
	entry = malloc(len);
	if (entry == NULL)
		return (-1);
	ft_strlcpy(entry, key, ft_strlen(key));
	ft_strlcat(entry, "=", len );
	ft_strlcat(entry, value, len );
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], key, ft_strlen(key)) == 0\
&& data->envp[i][ft_strlen(key)] == '=')
		{
			free(data->envp[i]);
			return(data->envp[i] = entry, 1);
		}
		i++;
	}
	return (ft_extend_env(data, entry));
}

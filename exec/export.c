/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:31:15 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/03 16:12:53 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

//print declare -x <string> for each env member
void ft_export_print_list(t_data *data)
{
	int i;

	i = 0;
	while (data->envp[i] != NULL)
	{
		printf("declare -x %s\n", data->envp[i]);
		i++;
	}
}

//helper function
static int ft_key_value_helper(char *argument, t_data *data)
{
	char	*key;
	char	*value;
	int		j;
	int		res;

	j = 0;
	while (argument[j] != '=')
		j++;
	key = ft_calloc(j + 1, sizeof(char));
	value = ft_strdup(argument + j + 1);
	if (key == NULL || value == NULL)
		return (-1);
	ft_strlcpy(key, argument, j + 1);
	res = ft_change_env_key_value(key, value, data);
	free(key);
	free(value);
	return (res);	
}

//add either a key or key and value pair to env
int ft_add_to_export_list(char **arguments, t_data *data)
{
	int		i;
	int		j;
	char	*entry;

	i = 1;
	while (arguments[i] != NULL)
	{
		j = 0;
		if (ft_strchr(arguments[i], '=') == NULL)
		{
			entry = ft_strdup(arguments[i]);
			if (entry == NULL)
				return (-1);
			ft_change_env_key(entry, data);
		}
		else
		{
			if (ft_key_value_helper(arguments[i], data) < 0)
				return (-1);
		}
		i++;
	}
	return (1);
}
	
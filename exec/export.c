/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:31:15 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/31 15:30:54 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

	void ft_export_print_list()
	{
		
	}
	void ft_add_to_export_list(char **arguments, t_data *data)
	{
		int i;
		int j;
		char *entry;

		i = 1;
		while (arguments[i] != NULL)
		{
			j = 0;
			if (ft_strchr(arguments[i], '=') == NULL)
			{
				entry = ft_calloc(ft_strlen(arguments[i]), sizeof(char));
				entry = ft_strdup(arguments[i]);
				ft_change_env_key(entry, data);
			}
			else
			{
				//TODO export with key=value pair
			}
		}
	}
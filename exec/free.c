/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:52:21 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/10 11:59:37 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//free array that is null terminated
void	ft_free_arr(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

// free an array from [0] to [i] incase of malloc failure
void	ft_free_r(void **array, int i)
{
	while (i >= 0)
	{
		free(array[i--]);
	}
	free(array);
}
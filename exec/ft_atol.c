/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:36:33 by jjhurry           #+#    #+#             */
/*   Updated: 2026/04/03 16:42:58 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <limits.h>

static long	ft_atol_help(const char *ptr, int sign)
{
	long	number;

	number = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		number = (number * 10) + *ptr - '0';
		ptr++;
	}
	while (*ptr == ' ' || *ptr == '\t' || *ptr == '\r' || \
*ptr == '\n' || *ptr == '\f' || *ptr == '\v')
		ptr++;
	if (*ptr != '\0')
		return (LONG_MAX);
	number *= sign;
	return (number);
}

//converts a string with possible char to integer
long	ft_atol(const char *ptr)
{
	int		sign;
	long	res;

	sign = 1;
	while (*ptr == ' ' || *ptr == '\t' || *ptr == '\r' || \
*ptr == '\n' || *ptr == '\f' || *ptr == '\v')
		ptr++;
	if (*ptr == 43 || *ptr == 45)
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	if (!(*ptr >= '0' && *ptr <= '9'))
		return (LONG_MAX);
	res = ft_atol_help(ptr, sign);
	if (res == LONG_MAX)
		return (LONG_MAX);
	else
		return (res);
}
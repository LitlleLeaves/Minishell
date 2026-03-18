/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 21:19:48 by side-lan          #+#    #+#             */
/*   Updated: 2026/03/18 21:21:09 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//different strjoin!!!
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;

	if (!str && s2 != NULL)
		return (ft_substr(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(str, s2, len + 1);
	str[len] = '\0';
	return (str);
}

char	*ft_substr(char *str)
{
	char	*new;
	int 	counter;
	int		size;

	if (!str)
		return (printf("empty string"), NULL);
	size = ft_strlen(str);
	counter = 0;
	new	= malloc(sizeof(char) * size);
	if (!new)
		return (printf("malloc error"), NULL);
	
	while (str[counter] != '\0')
	{
		new[counter] = str[counter];
		counter++;
	}
	new[counter] = '\0';
	return (new);
}

int		ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}
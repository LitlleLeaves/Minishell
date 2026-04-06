/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:23:46 by side-lan          #+#    #+#             */
/*   Updated: 2026/04/06 21:07:35 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h" 

bool	check_expansions(t_data *d)
{
	//char	*temp;
	int		index;

	index = 0;
	while (d->line[index] != '\0')
	{
		if (d->line[index] == '\'')
		{
			index++;
			while (d->line[index] != '\'' && d->line[index] != '\0')
				index++;
		}
		if (d->line[index] == '$')
		{
			convert_expansions(d, index);
		}
		//else
			index++;
	}
	return (true);
}

char	*get_key(char *line, int start)
{
	int		index;
	char	*key;

	index = 1;
	//if (line[start + index] == '\'' || line[start + index] == '"')
		//return (); moete ff kieke of we quotes zien als vlaide keys anders word dit n error
	while (line[start + index] != '\0' && check_delimeters(line[start + index]) == 0 && \
			line[start +index] != '"' && line[start +index] != '\'')
		index++;
	key = ft_substr(line, start, index);
	if (!key)
		return (printf("error in getkey\n"), NULL);
	//printf("key%s\n", key);
	return (key);
}

bool	convert_expansions(t_data *d, int start)
{
	int		index;
	char	*key;
	char	*value;
	int		length;
	int		key_length;

	index = 0;
	start++;
	key = get_key(d->line, start);
	key_length = ft_strlen(key);
	value = ft_getenv(d, key);
	length = ft_strlen(value);
	if (replace_key_in_line(d, value, start - 1, length, key_length) == false)
		return (printf("ERROR\n"), false);
	//printf()
	//printf("value%s\n", value);
	return (true);
}
bool	replace_key_in_line(t_data *d, char *value, int start, int val_len, int key_len)
{
	int		index;
	char	*new;
	int		old_len;
	int		tot_len;
	int		val_index;

	val_index = 0;
	index = 0;
	old_len = ft_strlen(d->line);
	tot_len = (val_len - key_len + 1) + (old_len + 1);
	new = malloc(tot_len);
	if (!new)
		return (printf("mallocerror\n"), false);
	while (index < start)
	{
		new[index] = d->line[index];
		index++;
	}	
	while (index < start + val_len + 1)
		new[index++] = value[val_index++];
	while (index < tot_len)
	{
		new[index] = d->line[index + val_len - key_len];
		index++;
	}
	new[index] = '\0';
	printf("%s\n", new);
	d->line = ft_strdup(new);
	return (new);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*ucs1;
	const unsigned char	*ucs2;
	size_t				i;

	i = 0;
	ucs1 = (const unsigned char *)s1;
	ucs2 = (const unsigned char *)s2;
	while ((ucs1[i] || ucs2[i]) && i < n)
	{
		if (ucs1[i] != ucs2[i])
			return (ucs1[i] - ucs2[i]);
		i++;
	}
	return (0);
}

char *ft_getenv(t_data *data, char *var)
{
	int		i;
	size_t	len;

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
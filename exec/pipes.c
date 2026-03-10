/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhurry <jjhurry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:53:26 by jjhurry           #+#    #+#             */
/*   Updated: 2026/03/10 13:20:14 by jjhurry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
//count the amount of pipes
int	ft_find_pipes(t_token *head)
{
	int		nmb_of_pipes;
	t_token	*curr;

	curr = head;
	if (curr == NULL)
		return (-1);
	nmb_of_pipes = 0;
	while(curr != NULL)
	{
		if (curr->type == PIPE)
			nmb_of_pipes++;
		curr = curr->next;
	}
	return (nmb_of_pipes);
}

//initilise the arrays to store pids and pipes, and create the pipes
int ft_create_pipes_and_pids(int nmb_of_pipes, t_data *data)
{
	int	i;

	data->pids = ft_calloc(nmb_of_pipes + 1, sizeof(pid_t));
	if (data->pids == NULL)
		return (-1);
	i = 0;
	data->pipes = ft_calloc(nmb_of_pipes, sizeof(int *));
	if (data->pipes == NULL)
		return (free(data->pids), -2);
	while (i < nmb_of_pipes)
	{
		data->pipes[i] = ft_calloc(2, sizeof(int));
		if (data->pipes[i] == NULL)
			return (free(data->pids), ft_free_r((void **)data->pipes, i), -3);
		if (pipe(data->pipes[i]) < 0)
			return (free(data->pids), ft_free_r((void **)data->pipes, i), -4);
		i++;
	}
	return (1);
}

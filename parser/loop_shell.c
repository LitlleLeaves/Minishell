/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:30:48 by side-lan          #+#    #+#             */
/*   Updated: 2026/03/18 21:22:23 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


int	main(int argc, char *argv[])
{
	argc = 0;
	argv[0] = 0;
	main_loop();
	return (0);
}
//main loop of te shell
int		main_loop(void)
{
	char	*line;
	t_token	*head;
	
	while (true)
	{
		printf("> ");
		line = read_input();
		if (line == NULL)
			return (0);
		//tokenize_input(line);
		//print_result
		usleep(500);
	}
}

char	*read_input(void)
{
	char	*line;
	char	*temp;
	int		read_return;

	read_return = 0;
	temp = malloc(1024 * sizeof(char));
	if (!temp)
		return (printf("malloc fail"), 0);
	while (temp != NULL)
	{
		read_return	= read(0, line, 1024);
		if (read_return == -1)
			return (printf("read error"), NULL);
		line = strjoin(line, temp);
		free(temp);
	}
}


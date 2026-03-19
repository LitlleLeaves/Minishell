/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:30:48 by side-lan          #+#    #+#             */
/*   Updated: 2026/03/19 19:15:37 by side-lan         ###   ########.fr       */
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
	char 	*temp;
	char	*line;
	t_token	*head;

	printf("yes\n");
	while (1)
	{
		printf("minishell > ");
		fflush(stdout);
		line = get_line();
		if (line == NULL)
			return (0);
		//temp = line;
		//line = parse(line);
		//free(temp);
		temp = line;
		head = tokenize_input(line);
		free(temp);
		//print_result
		usleep(500);
	}
}

//char	*parse(char *line)
//{
//	int	counter;
	
//}

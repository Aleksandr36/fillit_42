/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 11:32:53 by anjada            #+#    #+#             */
/*   Updated: 2019/09/24 15:49:12 by anjada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int   main(int ac, char **av)
{
	char  *line;
	int   fd1;
	int   fd2;

	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafujima <mafujima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:00:56 by mafujima          #+#    #+#             */
/*   Updated: 2025/10/26 22:10:26 by mafujima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc < 2)
	{
		printf("Please enter as follows: %s + filename", argv[0]);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open failed");
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("ret:%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
}
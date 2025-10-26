/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafujima <mafujima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:01:15 by mafujima          #+#    #+#             */
/*   Updated: 2025/10/26 21:58:21 by mafujima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*tmp;
	char		*line;	

	line = NULL;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = (char *)malloc(sizeof(char) * 1);
		stash[0] = '\0';	
	}
	if (stash && !ft_strchr_gnl(stash, '\n'))
	{
		stash = ft_read_and_join(fd, stash);
	}
	if (!stash || !*stash)
	{
		return (free(stash), stash = NULL, NULL);
	}
	line = ft_extract_line(stash);
	if (!line)
		return(free(stash), stash = NULL, NULL);
	tmp = ft_update_stash_after_line(stash);
	if (!tmp)
		return (stash = NULL, line);
	stash = tmp;
	return (line);
}
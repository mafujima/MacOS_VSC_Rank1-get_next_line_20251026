/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafujima <mafujima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:01:15 by mafujima          #+#    #+#             */
/*   Updated: 2025/10/26 22:34:11 by mafujima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strndup(const char *stash, size_t n)
{
	char	*res;
	char	*p;
	size_t	len_to_copy;

	len_to_copy = ft_strlen_gnl(stash);
	if (ft_strlen_gnl(stash) < n)
		len_to_copy = ft_strlen_gnl(stash);
	else
		len_to_copy = n;
	res = (char *)malloc(sizeof(char) * (len_to_copy + 1));
	if (res == NULL)
		return (NULL);
	p = res;
	while (*stash && len_to_copy--)
		*p++ = *stash++;
	*p = '\0';
	return (res);
}

char	*ft_strchr_gnl(const char *stash, int c)
{
	if (stash == NULL)
		return (NULL);
	while (*stash != '\0' && *stash != (char)c)
		stash++;
	if (*stash == (char)c)
		return ((char *)stash);
	else
		return (NULL);
}

size_t	ft_strlen_gnl(const char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i])
		i++;
	return (i);
}

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
		stash = ft_read_and_join(fd, stash);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	line = ft_extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	tmp = ft_update_stash_after_line(stash);
	if (!tmp)
		return (stash = NULL, line);
	stash = tmp;
	return (line);
}

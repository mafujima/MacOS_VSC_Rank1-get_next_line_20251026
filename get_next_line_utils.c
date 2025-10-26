/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafujima <mafujima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:43:41 by mafujima          #+#    #+#             */
/*   Updated: 2025/10/26 22:33:55 by mafujima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*read from fd to the buffer, till /n found*/
char	*ft_read_and_join(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	ssize_t	b_r;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	tmp = NULL;
	b_r = 1;
	while ((ft_strchr_gnl(stash, '\n') == NULL) && b_r > 0)
	{
		b_r = read(fd, buffer, BUFFER_SIZE);
		buffer[b_r] = '\0';
		if (b_r <= 0)
			break ;
		tmp = ft_strjoin_gnl(stash, buffer);
		if (!tmp)
			return (free(stash), free(buffer), stash = NULL, NULL);
		free(stash);
		stash = tmp;
	}
	free(buffer);
	if (b_r < 0)
		return (free(stash), stash = NULL, NULL);
	return (stash);
}

char	*ft_extract_line(char *stash)
{
	char	*res;

	if (!ft_strchr_gnl(stash, '\n'))
		return (ft_strdup_gnl(stash));
	res = ft_gnl_strndup(stash, (size_t)((ft_strchr_gnl(stash, '\n')
					- stash) + 1));
	return (res);
}

char	*ft_update_stash_after_line(char *stash)
{
	char	*n;
	char	*new_line;

	n = NULL;
	new_line = NULL;
	if (!stash)
		return (NULL);
	n = ft_strchr_gnl(stash, '\n');
	if (!n)
		return (free(stash), NULL);
	if (*(n + 1) == '\0')
		return (free(stash), stash = NULL, NULL);
	new_line = ft_strdup_gnl(n + 1);
	if (!new_line)
		return (free(stash), stash = NULL, NULL);
	free(stash);
	return (new_line);
}

char	*ft_strjoin_gnl(char *stash, char *buffer)
{
	char	*p;
	char	*res;

	if (ft_strlen_gnl(stash) == 0 && ft_strlen_gnl(buffer) == 0)
		return (NULL);
	res = (char *)malloc(sizeof(char) * ((ft_strlen_gnl(stash)
					+ ft_strlen_gnl(buffer)) + 1));
	if (!res)
		return (NULL);
	p = res;
	while (*stash)
		*p++ = *stash++;
	while (*buffer)
		*p++ = *buffer++;
	*p = '\0';
	return (res);
}

char	*ft_strdup_gnl(char *stash)
{
	char	*res;
	char	*p;

	if (!stash)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen_gnl(stash) + 1));
	if (res == NULL)
		return (NULL);
	p = res;
	while (*stash)
		*p++ = *stash++;
	*p = '\0';
	return (res);
}

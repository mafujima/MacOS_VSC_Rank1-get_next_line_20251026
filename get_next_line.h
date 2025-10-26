/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafujima <mafujima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:01:19 by mafujima          #+#    #+#             */
/*   Updated: 2025/10/26 06:18:23 by mafujima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE <= 0
#  error "ERROR : BUFFER_SIZE must be equal or greater than 1"
# endif

# if BUFFER_SIZE > INT_MAX - 1
#  error "BUFFER_SIZE must be <= INT_MAX - 1"
# endif

char	*get_next_line(int fd);
char	*ft_read_and_join(int fd, char *stash);
char	*ft_strjoin_gnl(char *stash, char *buffer);
char	*ft_extract_line(char *stash);
char	*ft_strchr_gnl(const char *stash, int c);
size_t	ft_strlen_gnl(const char *stash);

char	    *ft_strdup_gnl(char *stash);
char		*ft_gnl_strndup(const char *s, size_t n);
char		*ft_gnl_strdup(const char *s);
char 		*ft_update_stash_after_line(char *stash);



#endif
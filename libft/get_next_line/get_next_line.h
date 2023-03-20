/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:01:44 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/20 09:37:04 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_utils(char const *s1, char const *s2);
size_t	ft_strlen_utils(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);

#endif

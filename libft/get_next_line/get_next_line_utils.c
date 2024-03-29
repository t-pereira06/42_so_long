/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:01:38 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/27 17:27:20 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_utils(const char *s, int c)
{
	const char	*ptr;

	ptr = &s[0];
	while (*ptr != '\0')
	{
		if (*ptr == c)
			return ((char *)ptr);
		ptr++;
	}
	if (c == '\0')
		return ((char *)ptr);
	return (0);
}

char	*ft_strjoin_utils(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_count;
	size_t	s2_count;
	size_t	len;

	len = ft_strlen_utils(s1) + ft_strlen_utils(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	s1_count = 0;
	s2_count = 0;
	while (s1[s1_count])
	{
		str[s1_count] = s1[s1_count];
		s1_count++;
	}
	while (s2[s2_count])
	{
		str[s1_count + s2_count] = s2[s2_count];
		s2_count++;
	}
	str[len - 1] = '\0';
	return (str);
}

size_t	ft_strlen_utils(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc_utils(size_t nmemb, size_t size)
{
	char	*final;
	size_t	total;
	size_t	i;

	total = size * nmemb;
	final = malloc(total);
	if (final == NULL)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		final[i] = 0;
		i++;
		total--;
	}
	return ((void *)final);
}

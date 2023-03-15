/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:33:20 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/15 11:26:50 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Check if the characters are valid*/
int	check_character(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i] != '\0')
	{
		while (array[i][j] != '\0')
		{
			if ((array[i][j] != PLAYER) && (array[i][j] != WALL) \
			&& (array[i][j] != EXIT) && (array[i][j] != COLLECTIBLE) \
			&& (array[i][j] != EMPTY))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(char *argv, t_invmap *invalid_map)
{
	char	**array;
	char	*line;
	char	*path;
	int		i;
	int		fd;

	i = 0;
	path = ft_strjoin("maps/", argv);
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		array[i] = line;
		free(line);
		i++;
	}
	close(fd);
	check_character(array);
	free(path);
}

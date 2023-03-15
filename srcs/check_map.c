/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:33:20 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/15 12:28:45 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	fill_array(char *argv)
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
		free(line);
		i++;
	}
	close(fd);
	free(path);
	return (array);
}

void	check_map(char *argv, t_check_map *stack_check_map)
{
	char	**array;

	array = fill_array(argv);
	if (check_character(array) == 0)
	{
		write(1, "Map Error! Invalid Character Found", 65);
		free(array);
		exit(1);
	}
	fill_stack_check_map(array, stack_check_map);
}

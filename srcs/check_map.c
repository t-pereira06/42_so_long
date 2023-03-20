/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:33:20 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/20 12:01:46 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**fill_array(char *argv)
{
	char	**array;
	char	*line;
	char	*path;
	int		i;
	int		fd;

	i = 0;
	array = (char **)malloc(sizeof(char *) * (count_lines() + 1));
	path = ft_strjoin("maps/", argv);
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		array[i] = line;
		free(line);
		i++;
	}
	close(fd);
	free(path);
	return (array);
}

void	check_map(char *argv, t_stack *stack)
{
	stack->map_array = fill_array(argv);
	check_character(stack->map_array, stack);
	check_map_size(stack);
}

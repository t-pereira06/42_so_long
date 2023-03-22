/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:33:20 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/20 16:50:46 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_array(char *argv, t_stack *stack)
{
	char	*line;
	char	*path;
	int		i;
	int		fd;

	i = 0;
	stack->map_array = (char **)malloc(sizeof(char *) * (stack->x + 1));
	path = ft_strjoin("maps/", argv);
	fd = open(path, O_RDONLY);
	while (i < stack->x)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i + 1, line);
		stack->map_array[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	close(fd);
	free(path);
}

void	check_map(char *argv, t_stack *stack)
{
	stack->x = count_lines(argv);
	stack->y = count_columns(argv);
	fill_array(argv, stack);
	check_map_size(stack);
	check_character(stack->map_array, stack);
}

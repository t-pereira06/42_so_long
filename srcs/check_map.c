/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:33:20 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/27 11:24:13 by tsodre-p         ###   ########.fr       */
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
	line = 0;
	stack->map_array = (char **)malloc(sizeof(char *) * (stack->rows + 1));
	path = ft_strjoin("maps/", argv);
	fd = open(path, O_RDONLY);
	while (i < stack->rows)
	{
		line = get_next_line(fd);
		stack->map_array[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	stack->map_array[i] = 0;
	close(fd);
	free(path);
}

void	check_map(char *argv, t_stack *stack)
{
	int	i;

	i = 1;
	stack->rows = count_lines(argv);
	fill_array(argv, stack);
	stack->columns = count_columns(stack->map_array[0]);
	check_map_size(stack);
	check_character(stack->map_array, stack);
}

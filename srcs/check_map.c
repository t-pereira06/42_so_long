/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:33:20 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/22 15:07:31 by tsodre-p         ###   ########.fr       */
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
	stack->map_array = (char **)malloc(sizeof(char *) * (8));
	path = ft_strjoin("maps/", argv);
	fd = open(path, O_RDONLY);
	while (i < 8)
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
	//erro esta quando executa o count columns e o count lines
	stack->y = count_columns(argv);
	stack->x = count_lines(argv);
	printf("%i", stack->y);
	printf("%i", stack->x);
	fill_array(argv, stack);
	check_map_size(stack);
	check_character(stack->map_array, stack);
}

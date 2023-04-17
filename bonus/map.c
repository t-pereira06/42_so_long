/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:33:20 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/17 10:22:18 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*Fill stack->map_array with the map from file.ber*/
void	fill_array(char *argv, t_stack *stack)
{
	char	*line;
	char	*path;
	int		i;
	int		fd;

	i = 0;
	line = 0;
	stack->map_array = (char **)malloc(sizeof(char *) * (stack->rows + 1));
	path = ft_strjoin("maps/bonus/", argv);
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		stack->map_array[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	stack->map_array[i] = 0;
	close(fd);
	free(path);
}

/*Calling functions to check if the map is valid*/
void	check_map(char *argv, t_stack *stack)
{
	stack->rows = count_lines(argv);
	fill_array(argv, stack);
	stack->columns = count_columns(stack->map_array[0]);
	check_map_size(stack);
	check_character(stack->map_array, stack);
	check_miscellaneous(stack);
}

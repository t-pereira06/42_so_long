/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:22:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/11 10:54:51 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*Checks if all rows have the same number of characters*/
int	count_char_in_line(char **array, int num_rows, int num_cols)
{
	int	i;
	int	j;
	int	char_count;

	i = 0;
	j = 0;
	char_count = 0;
	while (i < num_rows - 1)
	{
		while (array[i][j] != '\0')
		{
			char_count++;
			j++;
		}
		if (char_count != num_cols)
			return (0);
		char_count = 0;
		j = 0;
		i++;
	}
	return (1);
}

/*Checks if the map is surrounded by walls*/
int	surrounded_by_walls(char **array, int num_rows, int num_cols)
{
	int	i;

	i = 0;
	while (array[0][i] != '\0')
	{
		if (array[0][i] != WALL)
			return (0);
		i++;
	}
	i = 1;
	while (i < (num_rows - 1))
	{
		if (array[i][0] != WALL || array[i][num_cols - 1] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (array[num_rows - 1][i] != '\0')
	{
		if (array[num_rows - 1][i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

/*Calls functions to verify the map*/
void	check_map_size(t_stack *stack)
{
	if (count_char_in_line(stack->map_array, stack->rows, stack->columns) == 0)
	{
		write(1, "Map Error! Map is not valid!\n", 30);
		free_map(stack);
		exit(1);
	}
	if (surrounded_by_walls(stack->map_array, stack->rows, stack->columns) == 0)
	{
		write(1, "Map Error! Map is not surrounded by walls!\n", 44);
		free_map(stack);
		exit(1);
	}
}

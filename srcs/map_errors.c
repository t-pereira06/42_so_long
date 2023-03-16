/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:22:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/16 17:39:05 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Check if the characters are valid*/
void	check_character(char **array, t_stack *stack)
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
				write(1, "Error\nMap Error! Invalid Character Found", 65);
				free(stack->map_array);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	surrounded_by_walls(char **array, int num_cols, int num_rows)
{
	int	i;

	i = 0;
	while (array[0] != '\0')
	{
		if (array[0][i] != 1)
			return (0);
		i++;
	}
	i = 1;
	while (i < (num_rows - 1))
	{
		if (array[i][0] != 1 || array[i][num_rows - 1] != 1)
			return (0);
		i++;
	}
	i = 0;
	while (array[num_rows - 1] != '\0')
	{
		if (array[num_rows - 1][i] != 1)
			return (0);
		i++;
	}
	return (1);
}

void	check_map_size(char **array, t_stack *stack)
{
	int	num_cols;
	int	num_rows;

	num_cols = 0;
	num_rows = 0;
	num_cols = count_columns(stack->map_array);
	num_rows = count_lines(stack->map_array);
	if (surrounded_by_walls(stack->map_array, num_cols, num_rows) == 0)
	{
		write(1, "Error\nMap Error! Map is not valid", 65);
		free(stack->map_array);
		exit(1);
	}
	if (count_char_in_line(stack->map_array, num_cols, num_rows) == 0)
	{
		write(1, "Error\nMap Error! Map is not valid", 65);
		free(stack->map_array);
		exit(1);
	}
	//falta contar players, etc
	//n colunas iguais em cada linha
	//surrounded by walls
	//ver se tens player, etc
}

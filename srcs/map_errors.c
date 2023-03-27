/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:22:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/27 11:17:06 by tsodre-p         ###   ########.fr       */
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
	while (array[i] != NULL)
	{
		while (array[i][j] != '\0')
		{
			if ((array[i][j] != PLAYER) && (array[i][j] != WALL) \
			&& (array[i][j] != EXIT) && (array[i][j] != COLLECTIBLE) \
			&& (array[i][j] != EMPTY))
			{
				write(1, "Error\nMap Error! Invalid Character Found", 41);
				free(stack->map_array);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

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

void	check_map_size(t_stack *stack)
{
	if (surrounded_by_walls(stack->map_array, stack->rows, stack->columns) == 0)
	{
		write(1, "Map Error! Map is not surrounded by walls!", 43);
		free(stack->map_array);
		exit(1);
	}
	//tudo certo ate aqui
	if (count_char_in_line(stack->map_array, stack->rows, stack->columns) == 0)
	{
		write(1, "Map Error! Map is not valid!", 29);
		free(stack->map_array);
		exit(1);
	}
	//y = linhas
	//x = colunas
	//falta contar players, etc
	//n colunas iguais em cada linha
	//surrounded by walls
	//ver se tens player, etc
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:43:37 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/04 10:21:44 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Count how many of each miscellaneous exist*/
void	count_miscellaneous(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->rows)
	{
		while (j < stack->columns)
		{
			if (stack->map_array[i][j] == WALL)
				stack->wall++;
			else if (stack->map_array[i][j] == EMPTY)
				stack->empty++;
			else if (stack->map_array[i][j] == COLLECTIBLE)
				stack->collectible++;
			else if (stack->map_array[i][j] == PLAYER)
				stack->player++;
			else if (stack->map_array[i][j] == EXIT)
				stack->exit++;
			j++;
		}
		j = 0;
		i++;
	}
}

/*Check the values of the miscellaneous*/
void	check_miscellaneous(t_stack *stack)
{
	count_miscellaneous(stack);
	if (stack->player != 1)
	{
		write(1, "The map needs to have 1 Player only!", 37);
		free_map(stack);
		exit(1);
	}
	else if (stack->exit != 1)
	{
		write(1, "The map needs to have 1 Exit only!", 35);
		free_map(stack);
		exit(1);
	}
	else if (stack->collectible < 1)
	{
		write(1, "The map needs to have 1 or more Collectibles!", 46);
		free_map(stack);
		exit(1);
	}
}

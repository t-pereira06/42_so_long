/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:49:01 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/13 10:00:18 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"


/*Function to use mlx in the window to change image*/
void	change_collectible(t_stack *stack, int x, int y, int flag)
{
	if (flag == 0)
	{
		mlx_put_image_to_window(
			stack->mlx_ptr, stack->window_ptr, stack->img_c_1, x * 32, y * 32);
	}
	if (flag == 1)
	{
		mlx_put_image_to_window(
			stack->mlx_ptr, stack->window_ptr, stack->img_c_2, x * 32, y * 32);
	}
}

/*Function to change collectible image in the window */
void	collectible_animation(t_stack *stack, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->columns)
		{
			if (stack->map_array[i][j] == COLLECTIBLE)
				change_collectible(stack, j, i, flag);
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:30:02 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/14 10:14:44 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*Move enemy up in the window */
void	change_enemy_image_w(t_stack *stack, int x, int y)
{
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_i, x * 32, (y - 1) * 32);
	stack->map_array[y][x] = EMPTY;
	stack->map_array[y - 1][x] = ENEMY;
}

/*Move enemy left in the window */
void	change_enemy_image_a(t_stack *stack, int x, int y)
{
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_i, (x - 1) * 32, y * 32);
	stack->map_array[y][x] = EMPTY;
	stack->map_array[y][x - 1] = ENEMY;
}

/*Move enemy down in the window */
void	change_enemy_image_s(t_stack *stack, int x, int y)
{
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_i, x * 32, (y + 1) * 32);
	stack->map_array[y][x] = EMPTY;
	stack->map_array[y + 1][x] = ENEMY;
}

/*Move enemy right in the window */
void	change_enemy_image_d(t_stack *stack, int x, int y)
{
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_i, (x + 1) * 32, y * 32);
	stack->map_array[y][x] = EMPTY;
	stack->map_array[y][x + 1] = ENEMY;
}

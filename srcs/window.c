/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:21:09 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/04 16:09:25 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Get pointers to the images to the variables of the stack*/
void	get_images(t_stack *stack)
{
	int	*width;
	int	*height;

	width = &stack->img_width;
	height = &stack->img_height;
	stack->img_wall = mlx_xpm_file_to_image(
					stack->mlx_ptr, WALL_IMG, width, height);
	stack->img_empty = mlx_xpm_file_to_image(
					stack->mlx_ptr, EMPTY_IMG, width, height);
	stack->img_collectible = mlx_xpm_file_to_image(
					stack->mlx_ptr, COLLECTIBLE_IMG, width, height);
	stack->img_player_w = mlx_xpm_file_to_image(
					stack->mlx_ptr, PLAYER_W_IMG, width, height);
	stack->img_player_a = mlx_xpm_file_to_image(
					stack->mlx_ptr, PLAYER_A_IMG, width, height);
	stack->img_player_s = mlx_xpm_file_to_image(
					stack->mlx_ptr, PLAYER_S_IMG, width, height);
	stack->img_player_d = mlx_xpm_file_to_image(
					stack->mlx_ptr, PLAYER_D_IMG, width, height);
	stack->img_exit = mlx_xpm_file_to_image(
					stack->mlx_ptr, EXIT_IMG, width, height);
}

void	fill_window(t_stack *stack)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->columns)
		{
			if (stack->map_array[i][j] == WALL)
				mlx_put_image_to_window(stack->mlx_ptr, stack->window_ptr, stack->img_wall, x, y);
			else if (stack->map_array[i][j] == EMPTY)
				mlx_put_image_to_window(stack->mlx_ptr, stack->window_ptr, stack->img_empty, x, y);
			else if (stack->map_array[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(stack->mlx_ptr, stack->window_ptr, stack->img_collectible, x, y);
			else if (stack->map_array[i][j] == PLAYER)
				mlx_put_image_to_window(stack->mlx_ptr, stack->window_ptr, stack->img_player_w, x, y);
			else if (stack->map_array[i][j] == EXIT)
				mlx_put_image_to_window(stack->mlx_ptr, stack->window_ptr, stack->img_exit, x, y);
			x = x + 24;
			j++;
		}
		y = y + 24;
		i++;
	}
}

/*Start window of the program*/
void	start_window(t_stack *stack)
{
	int	rows;
	int	columns;

	rows = stack->rows * 24;
	columns = stack->columns * 24;
	stack->mlx_ptr = mlx_init();
	get_images(stack);
	stack->window_ptr = mlx_new_window(stack->mlx_ptr, columns, rows, "so_long");
	fill_window(stack);
	mlx_hook(stack->window_ptr, KeyPress, KeyPressMask, &handle_esc, stack);
	mlx_loop(stack->mlx_ptr);
}

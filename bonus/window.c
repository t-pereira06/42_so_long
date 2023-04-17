/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:21:09 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/17 12:18:52 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	stack->img_c_1 = mlx_xpm_file_to_image(
			stack->mlx_ptr, COLLECTIBLE_1_IMG, width, height);
		stack->img_c_2 = mlx_xpm_file_to_image(
			stack->mlx_ptr, COLLECTIBLE_2_IMG, width, height);
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
	stack->img_i = mlx_xpm_file_to_image(
			stack->mlx_ptr, ENEMY_IMG, width, height);
}

/*Fill window with the images of the map*/
void	fill_window(t_stack *stack, int i, int j)
{
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->columns)
		{
			if (stack->map_array[i][j] == WALL)
				image_conditions(stack, WALL, j * 32, i * 32);
			if (stack->map_array[i][j] == EMPTY)
				image_conditions(stack, EMPTY, j * 32, i * 32);
			if (stack->map_array[i][j] == COLLECTIBLE)
				image_conditions(stack, COLLECTIBLE, j * 32, i * 32);
			if (stack->map_array[i][j] == PLAYER)
				image_conditions(stack, PLAYER, j * 32, i * 32);
			if (stack->map_array[i][j] == EXIT)
				image_conditions(stack, EXIT, j * 32, i * 32);
			if (stack->map_array[i][j] == ENEMY)
				image_conditions(stack, ENEMY, j * 32, i * 32);
			j++;
		}
		i++;
	}
	mlx_string_put(
		stack->mlx_ptr, stack->window_ptr, 10, 15, 000000, "Moves:  ");
	mlx_string_put(
		stack->mlx_ptr, stack->window_ptr, 50, 15, 000000,"0");
}

/*Print images on the window*/
void	image_conditions(t_stack *stack, char miscellaneous, int x, int y)
{
	if (miscellaneous == WALL)
		mlx_put_image_to_window(
			stack->mlx_ptr, stack->window_ptr, stack->img_wall, x, y);
	if (miscellaneous == EMPTY)
		mlx_put_image_to_window(
			stack->mlx_ptr, stack->window_ptr, stack->img_empty, x, y);
	if (miscellaneous == COLLECTIBLE)
		mlx_put_image_to_window(
			stack->mlx_ptr, stack->window_ptr, stack->img_c_1, x, y);
	if (miscellaneous == PLAYER)
		mlx_put_image_to_window(
			stack->mlx_ptr, stack->window_ptr, stack->img_player_w, x, y);
	if (miscellaneous == EXIT)
		mlx_put_image_to_window(
			stack->mlx_ptr, stack->window_ptr, stack->img_exit, x, y);
	if (miscellaneous == ENEMY)
		mlx_put_image_to_window(
			stack->mlx_ptr, stack->window_ptr, stack->img_i, x, y);
}

/*Start window of the program*/
void	start_window(t_stack *stack)
{
	int	rows;
	int	columns;

	rows = stack->rows * 32;
	columns = stack->columns * 32;
	stack->mlx_ptr = mlx_init();
	get_images(stack);
	stack->window_ptr = mlx_new_window(
			stack->mlx_ptr, columns, rows, "so_long");
	fill_window(stack, 0, 0);
	mlx_hook(stack->window_ptr, KeyPress, KeyPressMask, &handle_moves, stack);
	mlx_hook(
		stack->window_ptr, DestroyNotify, ButtonPressMask, &handle_exit, stack);
	mlx_loop_hook(stack->mlx_ptr, animations, stack);
	mlx_loop(stack->mlx_ptr);
}

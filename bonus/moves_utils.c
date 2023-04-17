/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:52:05 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/17 12:18:03 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*Function to change images in the window when W key is pressed*/
void	change_images_w(t_stack *stack, int new_x, int new_y)
{
	char	*number_ascii;
	int		x;
	int		y;

	x = stack->player_x;
	y = stack->player_y;
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_player_w, new_x, new_y);
	stack->moves++;
	number_ascii = ft_itoa(stack->moves);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_wall, 0, 0);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_wall, 32, 0);
	mlx_string_put(
		stack->mlx_ptr, stack->window_ptr, 10, 15, 000000, "Moves:  ");
	mlx_string_put(
		stack->mlx_ptr, stack->window_ptr, 50, 15, 000000, number_ascii);
	free(number_ascii);
}

/*Function to change images in the window when A key is pressed*/
void	change_images_a(t_stack *stack, int new_x, int new_y)
{
	char	*number_ascii;
	int		x;
	int		y;

	x = stack->player_x;
	y = stack->player_y;
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_player_a, new_x, new_y);
	stack->moves++;
	number_ascii = ft_itoa(stack->moves);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_wall, 0, 0);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_wall, 32, 0);
	mlx_string_put(
		stack->mlx_ptr, stack->window_ptr, 10, 15, 000000, "Moves:  ");
	mlx_string_put(
		stack->mlx_ptr, stack->window_ptr, 50, 15, 000000, number_ascii);
	free(number_ascii);
}

/*Function to change images in the window when S key is pressed*/
void	change_images_s(t_stack *stack, int new_x, int new_y)
{
	char	*number_ascii;
	int		x;
	int		y;

	x = stack->player_x;
	y = stack->player_y;
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_player_s, new_x, new_y);
	stack->moves++;
	number_ascii = ft_itoa(stack->moves);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_wall, 0, 0);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_wall, 32, 0);
	mlx_string_put(
		stack->mlx_ptr, stack->window_ptr, 10, 15, 000000, "Moves:  ");
	mlx_string_put(
		stack->mlx_ptr, stack->window_ptr, 50, 15, 000000, number_ascii);
	free(number_ascii);
}

/*Function to change images in the window when D key is pressed*/
void	change_images_d(t_stack *stack, int new_x, int new_y)
{
	char	*number_ascii;
	int		x;
	int		y;

	x = stack->player_x;
	y = stack->player_y;
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_player_d, new_x, new_y);
	stack->moves++;
	number_ascii = ft_itoa(stack->moves);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_wall, 0, 0);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_wall, 32, 0);
	mlx_string_put(
		stack->mlx_ptr, stack->window_ptr, 10, 15, 000000, "Moves:  ");
	mlx_string_put(
		stack->mlx_ptr, stack->window_ptr, 50, 15, 000000, number_ascii);
	free(number_ascii);
}

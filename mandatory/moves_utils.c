/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:52:05 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/06 15:20:55 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Function to change images in the window when W key is pressed*/
void	change_images_w(t_stack *stack, int new_x, int new_y)
{
	int	x;
	int	y;

	x = stack->player_x;
	y = stack->player_y;
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_player_w, new_x, new_y);
	stack->moves++;
	ft_printf("%s", "Moves: ");
	ft_printf("%i", stack->moves);
	ft_printf("%s", "\n");
}

/*Function to change images in the window when A key is pressed*/
void	change_images_a(t_stack *stack, int new_x, int new_y)
{
	int	x;
	int	y;

	x = stack->player_x;
	y = stack->player_y;
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_player_a, new_x, new_y);
	stack->moves++;
	ft_printf("%s", "Moves: ");
	ft_printf("%i", stack->moves);
	ft_printf("%s", "\n");
}

/*Function to change images in the window when S key is pressed*/
void	change_images_s(t_stack *stack, int new_x, int new_y)
{
	int	x;
	int	y;

	x = stack->player_x;
	y = stack->player_y;
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_player_s, new_x, new_y);
	stack->moves++;
	ft_printf("%s", "Moves: ");
	ft_printf("%i", stack->moves);
	ft_printf("%s", "\n");
}

/*Function to change images in the window when D key is pressed*/
void	change_images_d(t_stack *stack, int new_x, int new_y)
{
	int	x;
	int	y;

	x = stack->player_x;
	y = stack->player_y;
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_empty, x * 32, y * 32);
	mlx_put_image_to_window(
		stack->mlx_ptr, stack->window_ptr, stack->img_player_d, new_x, new_y);
	stack->moves++;
	ft_printf("%s", "Moves: ");
	ft_printf("%i", stack->moves);
	ft_printf("%s", "\n");
}

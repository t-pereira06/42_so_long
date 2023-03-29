/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:21:09 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/29 16:00:22 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

/*void	fill_window(t_stack *stack)
{

}*/

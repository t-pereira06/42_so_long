/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:21:09 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/29 10:55:06 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_window(t_stack *stack)
{

}
void	get_images(t_stack *stack)
{
	stack->img_wall = mlx_xpm_to_image(stack->mlx_ptr, WALL_IMG, 32, 32);
	stack->img_empty = mlx_xpm_to_image(stack->mlx_ptr, EMPTY_IMG, 32, 32);
	stack->img_collectible = mlx_xpm_to_image(stack->mlx_ptr, COLLECTIBLE_IMG, 32, 32);
	stack->img_player_w = mlx_xpm_to_image(stack->mlx_ptr, PLAYER_W_IMG, 32, 32);
	stack->img_player_a = mlx_xpm_to_image(stack->mlx_ptr, PLAYER_A_IMG, 32, 32);
	stack->img_player_s = mlx_xpm_to_image(stack->mlx_ptr, PLAYER_S_IMG, 32, 32);
	stack->img_player_d = mlx_xpm_to_image(stack->mlx_ptr, PLAYER_D_IMG, 32, 32);
	stack->img_exit = mlx_xpm_to_image(stack->mlx_ptr, EXIT_IMG, 32, 32);
}

void	fill_window(t_stack *stack)
{

}

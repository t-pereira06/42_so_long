/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:49:01 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/12 14:22:57 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

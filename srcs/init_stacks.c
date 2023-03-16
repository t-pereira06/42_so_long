/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:23:16 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/16 15:28:09 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_stack(t_stack *stack)
{
	stack->mlx_ptr = 0;
	stack->window_ptr = 0;
	stack->img_wall = 0;
	stack->img_empty = 0;
	stack->img_collectible = 0;
	stack->img_player = 0;
	stack->img_exit = 0;
	stack->map_array = 0;
	stack->line = 0;
	stack->column = 0;
	stack->wall = 0;
	stack->empty = 0;
	stack->collectible = 0;
	stack->player = 0;
	stack->exit = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:23:16 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/15 12:20:36 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct(t_stack *stack)
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

void	init_stack_check_map(t_check_map *stack_check_map)
{
	stack_check_map->map_array = 0;
	stack_check_map->line = 0;
	stack_check_map->column = 0;
	stack_check_map->wall = 0;
	stack_check_map->empty = 0;
	stack_check_map->collectible = 0;
	stack_check_map->player = 0;
	stack_check_map->exit = 0;
}

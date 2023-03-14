/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:23:16 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/14 17:04:31 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(t_main_stack *main_stack)
{
	t_map	map;

	main_stack->map.map_array = 0;
	main_stack->map.collectible = 0;
	main_stack->map.column = 0;
	main_stack->map.empty = 0;
	main_stack->map.exit = 0;
	main_stack->map.line = 0;
	main_stack->map.player = 0;
	main_stack->map.wall = 0;
}

void	init_stacks(t_main_stack *main_stack)
{
	init_map(&main_stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:23:16 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/14 14:34:09 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_map(t_main main)
{
	t_map	map;

	map.map_array = 0;
	map.collectible = 0;
	map.collumn = 0;
	map.empty = 0;
	map.exit = 0;
	map.line = 0;
	map.player = 0;
	map.wall = 0;
}

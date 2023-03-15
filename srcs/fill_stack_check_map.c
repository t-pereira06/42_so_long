/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_check_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:14:06 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/15 12:23:07 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_stack_check_map(char **array, t_check_map *stack_check_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i] != '\0')
	{
		stack_check_map->map_array[i] = array[i];
		i++;
	}
}

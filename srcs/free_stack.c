/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:48:00 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/04 10:37:39 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Function to free the map_array from the stack*/
void	free_map(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->rows)
	{
		free(stack->map_array[i]);
		i++;
	}
	free(stack->map_array);
}

void	free_stack(t_stack *stack)
{
	free_map(stack);
	//free(stack->mlx_ptr);
	//free(stack->window_ptr);
	free(stack->img_wall);
	free(stack->img_empty);
	free(stack->img_collectible);
	free(stack->img_player_w);
	free(stack->img_player_a);
	free(stack->img_player_s);
	free(stack->img_player_d);
	free(stack->img_exit);
}

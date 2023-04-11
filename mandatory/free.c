/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:48:00 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/06 10:32:47 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Function to free the map_array and
check_path from the stack*/
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

/*Function to free the check_path from the stack*/
void	free_check_path(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->rows)
	{
		free(stack->check_path[i]);
		i++;
	}
	free(stack->check_path);
}

/*Function to free stack*/
void	free_stack(t_stack *stack)
{
	free_map(stack);
	free_check_path(stack);
	free(stack->mlx_ptr);
}

/*Function to free window*/
void	free_window(t_stack *stack)
{
	mlx_destroy_image(stack->mlx_ptr, stack->img_wall);
	mlx_destroy_image(stack->mlx_ptr, stack->img_empty);
	mlx_destroy_image(stack->mlx_ptr, stack->img_player_w);
	mlx_destroy_image(stack->mlx_ptr, stack->img_player_a);
	mlx_destroy_image(stack->mlx_ptr, stack->img_player_s);
	mlx_destroy_image(stack->mlx_ptr, stack->img_player_d);
	mlx_destroy_image(stack->mlx_ptr, stack->img_exit);
	mlx_destroy_image(stack->mlx_ptr, stack->img_collectible);
	mlx_destroy_window(stack->mlx_ptr, stack->window_ptr);
	mlx_destroy_display(stack->mlx_ptr);
}

/*Function to free the whole program*/
void	free_program(t_stack *stack)
{
	free_window(stack);
	free_stack(stack);
}

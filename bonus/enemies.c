/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:52:59 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/12 14:22:43 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*Get a random move for the enemy*/
void	random_move(t_stack *stack)
{
	int	random_move;

	random_move = rand() % 4;
	enemy_position(stack, random_move);
}

/*Function to check with miscellaneous is next in the window,
to know where to move the enemy*/
int	check_next_window(t_stack *stack, int x, int y)
{
	if (stack->map_array[y][x] == EMPTY)
		return (1);
	if (stack->map_array[y][x] == PLAYER)
	{
		write(1, "You Died 🔪 Good luck next time!", 35);
		free_program(stack);
		exit (0);
	}
	return (0);
}

/*Get enemy position*/
int	enemy_position(t_stack *stack, int random_move)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->columns)
		{
			if (stack->map_array[i][j] == ENEMY)
				enemy_move(stack, j, i, random_move);
			j++;
		}
		i++;
	}
	return (1);
}

/*Function to change enemy on the window and the map*/
void	enemy_move(t_stack *stack, int x, int y, int random_move)
{
	if (random_move == 0)
	{
		if (check_next_window(stack, x, y - 1) == 1)
			change_enemy_image_w(stack, x, y);
	}
	if (random_move == 1)
	{
		if (check_next_window(stack, x - 1, y) == 1)
			change_enemy_image_a(stack, x, y);
	}
	if (random_move == 2)
	{
		if (check_next_window(stack, x, y + 1) == 1)
			change_enemy_image_s(stack, x, y);
	}
	if (random_move == 3)
	{
		if (check_next_window(stack, x + 1, y) == 1)
			change_enemy_image_d(stack, x, y);
	}
}

/*Function for the loop hook to keep collectibles and enemy moving*/
int	animations(t_stack *stack)
{
	static int	i;
	int			num;

	num = 15000;
	i++;
	if (i == num * 2)
		collectible_animation(stack, 0);
	if (i == num * 3)
		random_move(stack);
	if (i == num * 5)
		collectible_animation(stack, 1);
	return (1);
}

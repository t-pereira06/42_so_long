/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:38:06 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/12 14:33:21 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*Function to change pplayer position in the stack*/
void	player_position(t_stack *stack, int player_x, int player_y)
{
	stack->player_x = player_x;
	stack->player_y = player_y;
}

/*Function to check with miscellaneous is next in the window,
according to the key pressed*/
int	check_next_miscellaneous(t_stack *stack, int x, int y)
{
	if (stack->map_array[y][x] == WALL)
		return (0);
	if (stack->map_array[y][x] == ENEMY)
	{
		free_program(stack);
		exit (0);
	}
	if (stack->map_array[y][x] == EXIT
		&& (stack->count_c != stack->collectible))
		return (0);
	if (stack->map_array[y][x] == COLLECTIBLE)
	{
		stack->count_c++;
		return (1);
	}
	if (stack->map_array[y][x] == EMPTY)
		return (1);
	if (stack->map_array[y][x] == EXIT
		&& (stack->count_c == stack->collectible))
	{
		write(1, "Congratulations! You passed the map! 🎉\n", 43);
		free_program(stack);
		exit (0);
	}
	return (0);
}

/*Function to move the images and change player position*/
void	do_move(t_stack *stack, char key, int x, int y)
{
	if (key == 'W')
	{
		change_images_w(stack, x * 32, (y - 1) * 32);
		player_position(stack, x, y - 1);
		stack->map_array[y][x] = EMPTY;
	}
	if (key == 'A')
	{
		change_images_a(stack, (x - 1) * 32, y * 32);
		player_position(stack, x - 1, y);
		stack->map_array[y][x] = EMPTY;
	}
	if (key == 'S')
	{
		change_images_s(stack, x * 32, (y + 1) * 32);
		player_position(stack, x, y + 1);
		stack->map_array[y][x] = EMPTY;
	}
	if (key == 'D')
	{
		change_images_d(stack, (x + 1) * 32, y * 32);
		player_position(stack, x + 1, y);
		stack->map_array[y][x] = EMPTY;
	}
}

/*Function to check which key was pressed and then
do the move according to the key*/
void	player_moves(t_stack *stack, char key)
{
	int	x;
	int	y;

	x = stack->player_x;
	y = stack->player_y;
	if (key == 'W')
		if (check_next_miscellaneous(stack, x, y - 1) == 1)
			do_move(stack, 'W', x, y);
	if (key == 'A')
		if (check_next_miscellaneous(stack, x - 1, y) == 1)
			do_move(stack, 'A', x, y);
	if (key == 'S')
		if (check_next_miscellaneous(stack, x, y + 1) == 1)
			do_move(stack, 'S', x, y);
	if (key == 'D')
		if (check_next_miscellaneous(stack, x + 1, y) == 1)
			do_move(stack, 'D', x, y);
}

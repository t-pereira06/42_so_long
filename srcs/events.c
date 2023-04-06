/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:09:15 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/06 12:17:11 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Handle mouse click exiting window*/
/*int	handle_exit(int keysysm, t_stack *stack)
{

}*/

/*Handle ESC click to exit window*/
int	handle_esc(int keysys, t_stack *stack)
{
	if (keysys == ESC)
	{
		free_program(stack);
		exit(0);
	}
	return (0);
}

/*Handle keys to move player around the map*/
int	handle_moves(int keysys, t_stack *stack)
{
	if (keysys == W)
		player_moves(stack, 'W');
	if (keysys == A)
		player_moves(stack, 'A');
	if (keysys == S)
		player_moves(stack, 'S');
	if (keysys == D)
		player_moves(stack, 'D');
	return (0);
}

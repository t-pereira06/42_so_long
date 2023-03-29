/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:09:15 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/29 16:00:54 by tsodre-p         ###   ########.fr       */
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
	printf("%i", keysys);
	if (keysys == ESC)
		mlx_destroy_window(stack->mlx_ptr, stack->window_ptr);
	return (0);
}


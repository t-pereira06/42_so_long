/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:09:15 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/05 11:40:28 by tsodre-p         ###   ########.fr       */
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

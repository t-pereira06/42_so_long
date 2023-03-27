/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:48:00 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/27 17:55:07 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Function to free the map_array from the stack*/
void	free_stack(t_stack *stack)
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

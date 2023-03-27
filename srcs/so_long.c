/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:14 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/27 15:42:20 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Start stacks*/
void	init_stack(t_stack *stack)
{
	stack->mlx_ptr = 0;
	stack->window_ptr = 0;
	stack->img_wall = 0;
	stack->img_empty = 0;
	stack->img_collectible = 0;
	stack->img_player = 0;
	stack->img_exit = 0;
	stack->map_array = 0;
	stack->rows = 0;
	stack->columns = 0;
	stack->wall = 0;
	stack->empty = 0;
	stack->collectible = 0;
	stack->player = 0;
	stack->exit = 0;
}

/*Main function of the program*/
int	main(int argc, char **argv)
{
	t_stack		stack;

	check_args(argc, argv);
	init_stack(&stack);
	check_map(argv[1], &stack);
}

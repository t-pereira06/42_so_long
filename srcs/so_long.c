/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:14 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/29 16:30:53 by tsodre-p         ###   ########.fr       */
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
	stack->img_player_w = 0;
	stack->img_player_a = 0;
	stack->img_player_s = 0;
	stack->img_player_d = 0;
	stack->img_exit = 0;
	stack->map_array = 0;
	stack->map_array_path = 0;
	stack->img_width = 32;
	stack->img_height = 32;
	stack->rows = 0;
	stack->columns = 0;
	stack->wall = 0;
	stack->empty = 0;
	stack->collectible = 0;
	stack->player = 0;
	stack->exit = 0;
	stack->player_x = 0;
	stack->player_y = 0;
}

/*Start window of the program*/
void	start_window(t_stack *stack)
{
	stack->mlx_ptr = mlx_init();
	stack->window_ptr = mlx_new_window(stack->mlx_ptr, 500, 500, "Ola");
	mlx_hook(stack->window_ptr, KeyPress, KeyPressMask, &handle_esc, stack);
	mlx_loop(stack->mlx_ptr);
}

/*Main function of the program*/
int	main(int argc, char **argv)
{
	t_stack		stack;

	check_args(argc, argv);
	init_stack(&stack);
	check_map(argv[1], &stack);
	check_map_path(&stack);
	start_window(&stack);
	free_stack(&stack);
}

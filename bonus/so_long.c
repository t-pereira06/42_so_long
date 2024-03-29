/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:14 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/13 10:59:12 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*Test function*/
void	print_map(t_stack *stack, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->columns)
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("%s", "\n");
		i++;
	}
}

/*Start stacks*/
void	init_stack(t_stack *stack)
{
	stack->img_wall = 0;
	stack->img_empty = 0;
	stack->img_c_1 = 0;
	stack->img_c_2 = 0;
	stack->img_player_w = 0;
	stack->img_player_a = 0;
	stack->img_player_s = 0;
	stack->img_player_d = 0;
	stack->img_exit = 0;
	stack->img_i = 0;
	stack->map_array = 0;
	stack->check_path = 0;
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
	stack->count_c = 0;
	stack->moves = 0;
}

/*Main function of the program*/
int	main(int argc, char **argv)
{
	t_stack		stack;

	check_args(argc, argv);
	stack.mlx_ptr = 0;
	stack.window_ptr = 0;
	init_stack(&stack);
	check_map(argv[1], &stack);
	check_map_path(&stack, argv[1]);
	//print_map(&stack, stack.map_array);
	start_window(&stack);
	free_program(&stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:14 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/15 12:22:04 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char** argv)
{
	t_check_map	*stack_check_map;
	t_stack		*stack;

	check_map(argv[1], stack_check_map);
	check_args(argc,argv);
	init_stacks(stack, stack_check_map);
}

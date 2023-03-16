/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:14 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/16 15:01:30 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char** argv)
{
	t_stack		stack;

	init_struct(&stack);
	check_args(argc,argv);
	check_map(argv[1], &stack);
}

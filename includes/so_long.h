/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:07 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/16 17:37:20 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define SIZE 64
# define PLAYER 'P'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'

/*Struct of the program*/
typedef struct stack
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img_wall;
	void	*img_empty;
	void	*img_collectible;
	void	*img_player;
	void	*img_exit;
	char	**map_array;
	int		line;
	int		column;
	int		wall;
	int		empty;
	int		collectible;
	int		player;
	int		exit;
}			t_stack;

/*Verify arguments passed to the program*/
int	check_args(int arg_count, char **args);

/*Start stack*/
void	init_stack(t_stack *stack);
void	init_stack_check_map(t_stack *stack);

//CHECK IF THE MAP IS OK
/*Check if the map is valid*/
void	check_map(char *argv, t_stack *stack);
int		count_columns(char	**array);
void	check_character(char **array, t_stack *stack);
int		count_lines(char **array);
void	check_map_size(char **array, t_stack *stack);
int		count_char_in_line(char **array, int num_cols, int num_rows);

#endif

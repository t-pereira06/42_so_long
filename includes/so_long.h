/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:07 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/27 15:54:11 by tsodre-p         ###   ########.fr       */
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
	int		rows;
	int		columns;
	int		wall;
	int		empty;
	int		collectible;
	int		player;
	int		exit;
}			t_stack;

/*check_args.c*/
int		check_args(int arg_count, char **args);

/*check_map.c*/
void	fill_array(char *argv, t_stack *stack);
void	check_map(char *argv, t_stack *stack);

/*map_errors.c*/
int		count_char_in_line(char **array, int num_rows, int num_cols);
int		surrounded_by_walls(char **array, int num_rows, int num_cols);
void	check_map_size(t_stack *stack);

/*map_utils.c*/
int		count_columns(char	*line);
int		count_lines(char *argv);
void	check_character(char **array, t_stack *stack);
void	count_miscellaneous(t_stack *stack);

/*map_utils_2.c*/
void	check_miscellaneous(t_stack *stack);

#endif

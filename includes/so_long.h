/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:07 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/15 17:44:29 by tsodre-p         ###   ########.fr       */
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

typedef struct check_map
{
	char	**map_array;
	int		line;
	int		column;
	int		wall;
	int		empty;
	int		collectible;
	int		player;
	int		exit;
}			t_check_map;

/*Verify arguments passed to the program*/
int	check_args(int arg_count, char **args);

/*Start stack*/
void	init_stack(t_stack *stack);
void	init_stack_check_map(t_check_map *stack_check_map);

//CHECK IF THE MAP IS OK
/*Check if the map is valid*/
void	check_map(char *argv, t_check_map *stack_check_map);
int		count_columns(char	**array);
int		check_character(char **array);
int		count_lines(char **array);

#endif

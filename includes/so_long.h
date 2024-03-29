/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:07 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/19 09:02:54 by tsodre-p         ###   ########.fr       */
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
# include "../minilibx-linux/mlx.h"

# define SIZE 32
# define PLAYER 'P'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define WALL_IMG "textures/mandatory/wall.xpm"
# define EMPTY_IMG "textures/mandatory/empty.xpm"
# define PLAYER_W_IMG "textures/mandatory/player_w.xpm"
# define PLAYER_A_IMG "textures/mandatory/player_a.xpm"
# define PLAYER_S_IMG "textures/mandatory/player_s.xpm"
# define PLAYER_D_IMG "textures/mandatory/player_d.xpm"
# define COLLECTIBLE_IMG "textures/mandatory/collectible.xpm"
# define EXIT_IMG "textures/mandatory/exit.xpm"

/*Struct of the program*/
typedef struct stack
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img_wall;
	void	*img_empty;
	void	*img_collectible;
	void	*img_player_w;
	void	*img_player_a;
	void	*img_player_s;
	void	*img_player_d;
	void	*img_exit;
	char	**map_array;
	char	**check_path;
	int		img_width;
	int		img_height;
	int		rows;
	int		columns;
	int		wall;
	int		empty;
	int		collectible;
	int		player;
	int		exit;
	int		player_x;
	int		player_y;
	int		count_c;
	int		moves;
}			t_stack;

/*check_args.c*/
int	check_extension(char *arg);
int		check_args(int arg_count, char **args);

/*check_map.c*/
void	fill_array(char *argv, t_stack *stack);
void	check_map(char *argv, t_stack *stack);

/*handle_events.c*/
int	handle_exit(t_stack *stack);
int	handle_moves(int keysys, t_stack *stack);

/*map_errors.c*/
int		count_char_in_line(char **array, int num_rows, int num_cols);
int		surrounded_by_walls(char **array, int num_rows, int num_cols);
void	check_map_size(t_stack *stack);

/*map_utils.c*/
int		count_columns(char	*line);
int		count_lines(char *argv);
void	check_character(char **array, t_stack *stack);
void	count_miscellaneous(t_stack *stack);
void	check_miscellaneous(t_stack *stack);

/*free.c*/
void	free_map(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_window(t_stack *stack);
void	free_program(t_stack *stack);
void	free_check_path(t_stack *stack);

/*check_map_path.c*/
void	check_map_path(t_stack *stack, char *argv);
int		flood_fill(t_stack *stack, char **map, int x, int y);
void	player_coordinates(t_stack *stack);
void	fill_map_path(t_stack *stack, char *argv);

/*window.c*/
void	start_window(t_stack *stack);
void	get_images(t_stack *stack);
void	image_conditions(t_stack *stack, char miscellaneous, int x, int y);
void	fill_window(t_stack *stack);

/*moves.c*/
void	change_images(t_stack *stack, int x, int y);
void	player_position(t_stack *stack, int player_x, int player_y);
int		check_next_miscellaneous(t_stack *stack, int x, int y);
void	player_moves(t_stack *stack, char key);
//void	do_move(t_stack *stack, char key);
void	do_move(t_stack *stack, char key, int x, int y);

/*moves_utils.c*/
void	change_images_w(t_stack *stack, int new_x, int new_y);
void	change_images_a(t_stack *stack, int new_x, int new_y);
void	change_images_s(t_stack *stack, int new_x, int new_y);
void	change_images_d(t_stack *stack, int new_x, int new_y);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:39:13 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/12 14:31:57 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define SIZE 32
# define PLAYER 'P'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'
# define ENEMY 'I'
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define WALL_IMG "textures/bonus/wall.xpm"
# define EMPTY_IMG "textures/bonus/empty.xpm"
# define PLAYER_W_IMG "textures/bonus/player_w.xpm"
# define PLAYER_A_IMG "textures/bonus/player_a.xpm"
# define PLAYER_S_IMG "textures/bonus/player_s.xpm"
# define PLAYER_D_IMG "textures/bonus/player_d.xpm"
# define COLLECTIBLE_1_IMG  "textures/bonus/collectible_1.xpm"
# define COLLECTIBLE_2_IMG "textures/bonus/collectible_2.xpm"
# define EXIT_IMG "textures/bonus/exit.xpm"
# define ENEMY_IMG "textures/bonus/enemy.xpm"

/*Struct of the program*/
typedef struct stack
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img_wall;
	void	*img_empty;
	void	*img_c_1;
	void	*img_c_2;
	void	*img_player_w;
	void	*img_player_a;
	void	*img_player_s;
	void	*img_player_d;
	void	*img_exit;
	void	*img_i;
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
void	fill_window(t_stack *stack, int i, int j);

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

/*enemies.c*/
int		enemy_position(t_stack *stack, int random_move);
int		check_next_window(t_stack *stack, int x, int y);
void	enemy_move(t_stack *stack, int x, int y, int random_move);

/*enemies_utils.c*/
void	collectible_animation(t_stack *stack, int flag);
void	change_enemy_image_w(t_stack *stack, int x, int y);
void	change_enemy_image_a(t_stack *stack, int x, int y);
void	change_enemy_image_s(t_stack *stack, int x, int y);
void	change_enemy_image_d(t_stack *stack, int x, int y);

/*sprites.c*/
void	change_collectible(t_stack *stack, int x, int y, int flag);

#endif

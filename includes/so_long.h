/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:07 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/14 10:26:30 by tsodre-p         ###   ########.fr       */
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
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

/*Struct for the window*/
typedef struct mlx
{
	void	*mlx_ptr;
	void	*window_ptr;
}				t_mlx;

/*Struct for the images to make the map*/
typedef struct path
{
	void	*wall;
	void	*empty;
	void	*collectible;
	void	*player;
	void	*exit;
}				t_path;

/*Struct for the map*/
typedef struct map
{
	char	**map_array;
	int		line;
	int		collumn;
	int		wall;
	int		empty;
	int		collectible;
	int		player;
	int		exit;
}				t_map;

/*Struct to check if the map is valid*/
typedef struct invalid_map
{
	int	invalid_columns;
	int	invalid_borders;
	int	invalid_exit;
	int	invalid_collectibles;
	int	invalid_player;
	int	invalid_character;
	int	invalid_path;
	int	empty_fd;
}				t_inv_map;

/*Main struct of the program*/
typedef struct root
{
	t_map		map;
	t_map		floodfill;
	t_inv_map	map_err;
	t_mlx		mlx;
	t_path		path;
}			t_root;

/*Verify arguments passed to the program*/
int	check_args(int arg_count, char **args);

/**/

#endif

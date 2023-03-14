/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:07 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/14 15:26:26 by tsodre-p         ###   ########.fr       */
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

/*Struct for the window*/
typedef struct window
{
	void	*mlx_ptr;
	void	*window_ptr;
}				t_window;

/*Struct for the images to make the map*/
typedef struct images
{
	void	*wall;
	void	*empty;
	void	*collectible;
	void	*player;
	void	*exit;
}				t_images;

/*Struct for the map*/
typedef struct map
{
	char	**map_array;
	int		line;
	int		column;
	int		wall;
	int		empty;
	int		collectible;
	int		player;
	int		exit;
}				t_map;

/*Main struct of the program*/
typedef struct main_stack
{
	t_map		map;
	t_window	mlx;
	t_images	images;
}			t_main_stack;

/*Verify arguments passed to the program*/
void	check_args(int arg_count, char **args);

/**/

#endif

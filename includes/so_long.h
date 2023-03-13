/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:08:07 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/13 13:51:36 by tsodre-p         ###   ########.fr       */
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

typedef struct s_path
{
	void	*wall;
	void	*empty;
	void	*collectible;
	void	*player;
	void	*exit;
}				t_path;

typedef struct s_root
{
	t_path		path;
}			t_root;

#endif

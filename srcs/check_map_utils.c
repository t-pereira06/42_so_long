/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:22:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/15 12:00:23 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_columns(char	**array)
{
	int	i;

	while (array[i] != '\0')
		i++;
	return (i);
}

int	count_lines(char **array)
{
	int	i;

	while (array[0][i] != "\0")
		i++;
	return (i);
}

/*Check if the characters are valid*/
int	check_character(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i] != '\0')
	{
		while (array[i][j] != '\0')
		{
			if ((array[i][j] != PLAYER) && (array[i][j] != WALL) \
			&& (array[i][j] != EXIT) && (array[i][j] != COLLECTIBLE) \
			&& (array[i][j] != EMPTY))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:45:17 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/27 15:52:18 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Count map columns*/
int	count_columns(char	*line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	return (i);
}

/*Count map lines*/
int	count_lines(char *argv)
{
	char	*line;
	char	*path;
	int		i;
	int		fd;

	i = 0;
	path = ft_strjoin("maps/", argv);
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	free(line);
	free(path);
	close(fd);
	return (i);
}

/*Checks if all characters are valid*/
void	check_character(char **array, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->rows)
	{
		while (j < stack->columns)
		{
			if ((array[i][j] == PLAYER) || (array[i][j] == WALL) \
			|| (array[i][j] == EXIT) || (array[i][j] == COLLECTIBLE) \
			|| (array[i][j] == EMPTY))
			{
				j++;
			}
			else
			{
				write(1, "Map Error! Invalid Character Found!", 36);
				free(stack->map_array);
				exit(1);
			}
		}
		j = 0;
		i++;
	}
}

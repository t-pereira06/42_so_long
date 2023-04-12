/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:45:17 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/12 09:16:07 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
			|| (array[i][j] == EMPTY) || (array[i][j] == ENEMY))
			{
				j++;
			}
			else
			{
				write(1, "Map Error! Invalid Character Found!\n", 37);
				free_map(stack);
				exit(1);
			}
		}
		j = 0;
		i++;
	}
}

/*Count how many of each miscellaneous exist*/
void	count_miscellaneous(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->rows)
	{
		while (j < stack->columns)
		{
			if (stack->map_array[i][j] == WALL)
				stack->wall++;
			else if (stack->map_array[i][j] == EMPTY)
				stack->empty++;
			else if (stack->map_array[i][j] == COLLECTIBLE)
				stack->collectible++;
			else if (stack->map_array[i][j] == PLAYER)
				stack->player++;
			else if (stack->map_array[i][j] == EXIT)
				stack->exit++;
			j++;
		}
		j = 0;
		i++;
	}
}

/*Check the values of the miscellaneous*/
void	check_miscellaneous(t_stack *stack)
{
	count_miscellaneous(stack);
	if (stack->player != 1)
	{
		write(1, "The map needs to have 1 Player only!\n", 38);
		free_map(stack);
		exit(1);
	}
	else if (stack->exit != 1)
	{
		write(1, "The map needs to have 1 Exit only!\n", 36);
		free_map(stack);
		exit(1);
	}
	else if (stack->collectible < 1)
	{
		write(1, "The map needs to have 1 or more Collectibles!\n", 47);
		free_map(stack);
		exit(1);
	}
}

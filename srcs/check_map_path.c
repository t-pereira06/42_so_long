/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:25:35 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/05 11:45:43 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Fill a temporary map_array to use in flood_fill*/
void	fill_map_path(t_stack *stack, char *argv)
{
	char	*line;
	char	*path;
	int		i;
	int		fd;

	i = 0;
	line = 0;
	stack->check_path = (char **)malloc(sizeof(char *) * (stack->rows + 1));
	path = ft_strjoin("maps/", argv);
	fd = open(path, O_RDONLY);
	while (i < stack->rows)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		stack->check_path[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	stack->check_path[i] = 0;
	close(fd);
	free(path);
}

/*Get player coordinates on the map*/
void	player_coordinates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->rows)
	{
		j = 0;
		while (j < stack->columns)
		{
			if (stack->map_array[i][j] == PLAYER)
			{
				stack->player_x = j;
				stack->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

/*Function to check if a path exists*/
int	flood_fill(t_stack *stack, char **map, int x, int y)
{
	static int	collectibles;
	static int	exits;

	if (y < 0 || x < 0 || y > stack->rows || x > stack->columns
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == EXIT)
	{
		exits++;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == COLLECTIBLE)
		collectibles++;
	map[y][x] = 'X';
	flood_fill(stack, map, x + 1, y);
	flood_fill(stack, map, x - 1, y);
	flood_fill(stack, map, x, y + 1);
	flood_fill(stack, map, x, y - 1);
	if (exits == 1 && collectibles == stack->collectible)
		return (1);
	else
		return (0);
}

/*Check if there is a valid path in the map.
It means that the player can reach collectibles and exit.*/
void	check_map_path(t_stack *stack, char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	fill_map_path(stack, argv);
	player_coordinates(stack);
	if (flood_fill(
			stack, stack->check_path, stack->player_x, stack->player_y) == 0)
	{
		write(1, "Map Error! Invalid Path!", 25);
		free_check_path(stack);
		free_map(stack);
		exit(1);
	}
}

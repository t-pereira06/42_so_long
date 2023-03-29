/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:25:35 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/28 16:38:42 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map_path(t_stack *stack)
{
	int	i;

	i = 0;
	stack->map_array_path = (char **)malloc(sizeof(char *) * (stack->rows + 1));
	while (i < stack->rows)
	{
		stack->map_array_path[i] = stack->map_array[i];
		i++;
	}
	stack->map_array_path[i] = 0;
}

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

int	flood_fill(t_stack *stack, char **map, int x, int y)
{
	static int	collectibles;
	static int	exits;

	if (y < 0 || x < 0 || y > stack->rows || x > stack->columns
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
	{
		exits++;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == 'C')
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
void	check_map_path(t_stack *stack)
{
	fill_map_path(stack);
	player_coordinates(stack);
	if (flood_fill(stack, stack->map_array_path, stack->player_x, stack->player_y) == 0)
	{
		write(1, "Map Error! Invalid Path!", 25);
		free(stack->map_array_path);
		free_stack(stack);
		exit(1);
	}
	free(stack->map_array_path);
}

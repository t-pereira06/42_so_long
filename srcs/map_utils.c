/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:45:17 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/27 11:25:02 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_columns(char	*line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	return(i);
}

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

int	count_char_in_line(char **array, int num_rows, int num_cols)
{
	int	i;
	int	j;
	int	char_count;

	i = 0;
	j = 0;
	char_count = 0;
	while (i < num_rows - 1)
	{
		while (array[i][j] != '\0')
			char_count++;
		if (char_count != num_cols)
			return (0);
		char_count = 0;
		j = 0;
		i++;
	}
	return (1);
}

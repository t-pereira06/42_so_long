/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:45:17 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/16 17:38:09 by tsodre-p         ###   ########.fr       */
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

	while (array[0][i] != '\0')
		i++;
	return (i);
}

int	count_char_in_line(char **array, int num_cols, int num_rows)
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

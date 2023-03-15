/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:22:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/15 11:25:25 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

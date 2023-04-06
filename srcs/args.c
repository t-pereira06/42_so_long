/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:21:39 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/06 14:48:39 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Check if the extension of the file is .ber*/
int	check_extension(char *arg)
{
	char	*ext;

	ext = ft_strrchr(arg, '.');
	if (!(ext[0] == '.') || !(ext[1] == 'b') \
	|| !(ext[2] == 'e') || !(ext[3] == 'r'))
		return (0);
	return (1);
}

/*Check the arguments*/
int	check_args(int arg_count, char **args)
{
	char	*path;
	int		fd;

	if (arg_count != 2)
	{
		write(1, "Error\nRun program: ./so_long <map_name.ber>", 44);
		exit(1);
	}
	path = ft_strjoin("maps/", args[1]);
	fd = open(path, O_RDONLY);
	if (check_extension(args[1]) != 1)
	{
		write(1, "Error\nInvalid file extension!", 30);
		free(path);
		exit(1);
	}
	else if (fd < 0)
	{
		write(1, "Error\nInvalid file!", 20);
		free(path);
		exit(1);
	}
	free(path);
	return (1);
}

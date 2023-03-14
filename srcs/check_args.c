/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:21:39 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/14 14:21:32 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_extension(char *arg)
{
	char	*ext;

	ext = ft_strrchr(arg, '.');
	if (!(ext[0] == '.') || !(ext[1] == 'b') || !(ext[2] == 'e') || !(ext[3] == 'r'))
		return (0);
	return (1);
}

int	check_args(int arg_count, char **args)
{
	int	fd;

	fd = open(args[1], O_RDONLY);
	if (arg_count != 2)
		return (write(1, "Not enough arguments! Run program with ./so_long <map_name>.ber\n", 65));
	else if (check_extension(args[1]) != 1)
		return (write(1, "Invalid file extension! Run program with ./so_long <map_name>.ber\n", 67));
	else if (fd < 0)
		return (write(1, "Invalid file! Run program with ./so_long <map_name>.ber\n", 57));
	return (1);
}

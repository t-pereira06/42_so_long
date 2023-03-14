/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:21:39 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/03/14 13:22:38 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_extension(char *arg)
{
	char	*ext;

	ext = ft_strrchr(arg, '.');
	if (!(ext[0] == 'b') || !(ext[1] == 'e') || !(ext[2] == 'r'))
		return (0);
	return (1);
}

int	check_args(int arg_count, char **args)
{
	int	fd;

	fd = open(args[1], O_RDONLY);
	if (arg_count != 2)
		return (write(1, "Not enough arguments! \
		Run program with ./so_long <map_name>.ber\n", 65));
	else if (check_extension(args[1]) != 1)
		return (write(1, "Invalid file extension! \
		Run program with ./so_long <map_name>.ber\n", 69));
	else if (fd < 0)
		return (write(1, "Invalid file! \
		Run program with ./so_long <map_name>.ber\n", 69));
	return (1);
}

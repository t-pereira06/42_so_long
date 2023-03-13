/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:02:21 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/19 13:51:03 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlist(t_list *list)
{
	int	i;
	int	a;

	i = ft_lstsize(list);
	a = 0;
	if (i != 0)
	{
		while (list)
		{
			ft_printf("%s", list->content);
			list = list->next;
			a++;
		}
	}
}

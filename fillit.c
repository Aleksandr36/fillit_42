/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:30:39 by yshawn            #+#    #+#             */
/*   Updated: 2019/11/04 15:46:29 by anjada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_list	prev(t_list *list)
{
	if (list->previous)
	{
		list->x = list->previous->x + 1;
		list->y = list->previous->y;
	}
	else
	{
		list->x = 0;
		list->y = 0;
	}
	return (*list);
}

int				solver(t_list *list, short *map, int size)
{
	if (!list->tetro)
		return (1);
	prev(list);
	while (list->y + list->hight <= size)
	{
		while (list->x + list->width <= size)
		{
			if (!(*(long *)(map + list->y) & list->tetro << list->x))
			{
				(*(long *)(map + list->y) |= list->tetro << list->x);
				if (solver(list + 1, map, size))
					return (1);
				(*(long *)(map + list->y) ^= list->tetro << list->x);
			}
			list->x++;
		}
		list->x = 0;
		list->y++;
	}
	return (0);
}

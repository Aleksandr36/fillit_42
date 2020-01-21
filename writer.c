/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:30:27 by anjada            #+#    #+#             */
/*   Updated: 2019/11/04 15:38:07 by anjada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int				tet_width(unsigned long is)
{
	int		i;

	i = 0;
	while (is != 0)
	{
		is = is & 0xEEEF;
		is >>= 1;
		i++;
	}
	return (i);
}

static int				tet_hight(unsigned long is)
{
	int		i;

	i = 0;
	while (is != 0)
	{
		is >>= 4;
		i++;
	}
	return (i);
}

static unsigned long	bit_shift(unsigned long tet)
{
	tet = reverse_bits_64(tet);
	while (tet % 2 != 1)
	{
		tet >>= 1;
		if (tet == 116 || tet == 802 || tet == 54 || tet == 306 ||
				tet == 562 || tet == 114)
			break ;
	}
	return (tet);
}

static unsigned long	pre_rec(unsigned long tet)
{
	unsigned long	tet1;
	unsigned long	tet2;
	unsigned long	tet3;

	tet1 = (tet & 0xF) | ((tet << 12) & 983040);
	tet2 = (tet << 24) & 0xF00000000;
	tet3 = (tet << 36) & 0xF000000000000;
	tet = (tet1 | tet2) | tet3;
	return (tet);
}

t_list					rec_tetromino(unsigned short int si, t_list list, int i)
{
	char			letter;
	unsigned long	is;

	letter = 'A';
	is = bit_shift((unsigned long)si);
	list.tetro = pre_rec(is);
	list.width = tet_width(is);
	list.hight = tet_hight(is);
	list.letter = letter + i;
	return (list);
}

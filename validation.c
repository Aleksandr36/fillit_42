/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:22:46 by anjada            #+#    #+#             */
/*   Updated: 2019/11/22 22:32:45 by anjada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** checking tetramino for validation
** every tetramino should have 3 or 4 (for square) links(communications)
** ###   has 2 horizontal links and 1 vertical link
**  #
**
** ####  has 3 horizontal links and 0 vertical link
**
** ##    has 2 horizontal links and 2 vertical links
** ##
**
** so, in summ hor + ver must have 3 or 4 (if hor == 2 and ver == 2)
** in other cases, tetramino is not valid
*/

static int				is_valid_tetramino(int si)
{
	int					i;
	int					hor;
	int					ver;
	int					s_bit;

	i = 16;
	hor = 0;
	ver = 0;
	while (--i > -1)
	{
		s_bit = 1;
		if (1 << i & si)
		{
			s_bit = s_bit << i;
			if (si & s_bit >> 1)
				hor++;
			if (si & s_bit >> 4)
				ver++;
		}
	}
	if (hor + ver != 3 && (hor != 2 || ver != 2))
		error();
	if ((hor + ver == 4) && (hor != 2 && ver != 2))
		error();
	return (1);
}

/*
** checking buf for validity
** lt (lattice) should be 4, pt (point) should be 12, co (carryover) should be 4
** at start we have si (0000 0000 0000 0000), when we meet '#' we change bit
** in i-position in si (0000 1000 1110 0000)
*/

void					is_valid_file_ln_brk(int n, int lt, int pt, char buf)
{
	if (n != 0 && (n + 1) % 5 == 0)
	{
		if ((lt + pt) % 4 != 0)
			error();
		if (buf != '\n')
			error();
	}
	return ;
}

void					is_valid_file_lt_pt(int lt, int pt, int si)
{
	if (lt != 4 || pt != 12)
		error();
	else
		is_valid_tetramino(si);
	return ;
}

static int				is_valid_file(char *buf)
{
	int					i;
	int					n;
	int					pt;
	int					lt;
	int					si;

	i = 15;
	n = 0;
	pt = 0;
	lt = 0;
	si = 0;
	while (*(buf + n) != '\0')
	{
		is_valid_file_ln_brk(n, lt, pt, *(buf + n));
		*(buf + n) == '.' ? pt++ : pt + 0;
		if (*(buf + n) == '#')
		{
			si |= (1 << i);
			lt++;
		}
		*(buf + n) != '\n' ? i-- : i + 0;
		n++;
	}
	is_valid_file_lt_pt(lt, pt, si);
	return (si);
}

/*
** reading file
** checking for max tetraminos in one file, it must be less than 26(inclusive)
** checking for ret (must be 21, or 20 if it's end of file)
** after cycle buf should be 20, because end of file
** sending tetramino to is_valid_file
*/

int						reading_file(char *argv, t_list *tetromino)
{
	int					i;
	int					fd;
	int					ret;
	char				buf[BUF_SIZE];

	i = 0;
	if (!(fd = open(argv, O_RDONLY)))
		error();
	else
		while ((ret = read(fd, buf, BUF_SIZE - 1)) > 0)
		{
			if (ret != 21 && ret != 20)
				error();
			i > 25 ? error() : i + 0;
			*(buf + ret) = '\0';
			tetromino[i] = rec_tetromino(is_valid_file(buf), tetromino[i], (i));
			i++;
		}
	if (ft_strlen(buf) != 20)
		error();
	return (i);
}

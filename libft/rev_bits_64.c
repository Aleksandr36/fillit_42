/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_bits_64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:50:56 by anjada            #+#    #+#             */
/*   Updated: 2019/11/04 14:54:24 by anjada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	reverse_bits_64(unsigned long tet)
{
	int				i;
	unsigned long	x;
	unsigned long	res;

	x = 1;
	i = 63;
	res = 0;
	while (i > 0)
	{
		res = res | ((tet & x) << i);
		x = x << 1;
		i -= 2;
	}
	i = 1;
	while (i < 64)
	{
		res = res | ((tet & x) >> i);
		x = x << 1;
		i += 2;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:17:26 by anjada            #+#    #+#             */
/*   Updated: 2019/11/04 16:02:01 by anjada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 22

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

typedef struct			s_list
{
	unsigned long		tetro;
	char				letter;
	int					x;
	int					y;
	int					hight;
	int					width;
	struct s_list		*previous;
}						t_list;

void					error(void);
int						reading_file(char *argv, t_list *tetromino);
t_list					rec_tetromino(unsigned short int si, t_list list,
		int count);
int						solver(t_list *list, short *map, int size);

#endif

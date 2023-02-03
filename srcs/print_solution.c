/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:36:33 by hthomas           #+#    #+#             */
/*   Updated: 2019/09/16 10:36:34 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	print_solution(int **tab, t_motif *motif, t_square *size,
	t_square *square)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*size).ymax)
	{
		x = 0;
		while (x < (*size).xmax)
		{
			if (tab[y][x] == -1)
				ft_putchar((*motif).obstacle);
			else if ((x >= (*square).xmin && x <= (*square).xmax)
				&& (y >= (*square).ymin && y <= (*square).ymax))
				ft_putchar((*motif).plain);
			else
				ft_putchar((*motif).empty);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

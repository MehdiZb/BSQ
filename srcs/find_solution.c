/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:39:29 by hthomas           #+#    #+#             */
/*   Updated: 2019/09/16 13:39:30 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_square	*find_bigest_square(int **tab, t_square *square, t_square *size)
{
	int			max;
	int			y;
	int			x;

	max = -1;
	y = 0;
	while (y < (*size).ymax)
	{
		x = 0;
		while (x < (*size).xmax)
		{
			if (tab[y][x] > max)
			{
				max = tab[y][x];
				(*square).xmax = x;
				(*square).ymax = y;
				(*square).xmin = x - max;
				(*square).ymin = y - max;
			}
			x++;
		}
		y++;
	}
	return (square);
}

int			min_3(int **t, int x, int y)
{
	int	min;

	min = 0;
	if (x == 0 || y == 0)
		return (-1);
	min = ((t[y - 1][x] < t[y - 1][x - 1]) ? t[y - 1][x] : t[y - 1][x - 1]);
	return ((min < t[y][x - 1]) ? min : t[y][x - 1]);
}

int			**set_nb_in_tab(int **tab_solution, t_square *size)
{
	int	y;
	int	x;

	y = 0;
	while (y < (*size).ymax)
	{
		x = 0;
		while (x < (*size).xmax)
		{
			if (tab_solution[y][x] != -1)
				tab_solution[y][x] = min_3(tab_solution, x, y) + 1;
			x++;
		}
		y++;
	}
	return (tab_solution);
}

t_square	find_solution(int **tab_map, t_square *size)
{
	int			**tab_solution;
	t_square	square;

	tab_solution = set_nb_in_tab(tab_map, size);
	find_bigest_square(tab_solution, &square, size);
	return (square);
}

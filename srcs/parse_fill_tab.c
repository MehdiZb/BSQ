/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:56:11 by hthomas           #+#    #+#             */
/*   Updated: 2019/09/17 17:24:27 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	**parse_fill_tab(int **tab, char *str, t_motif *motif, int line_length)
{
	int	y;
	int x;

	y = 0;
	while (y < (*motif).nb_lines)
	{
		if (!(tab[y] = malloc(line_length * (sizeof(int)))))
			return (ft_free_tab(tab, y - 1));
		x = 0;
		while (x < line_length)
		{
			if (*str++ == (*motif).obstacle)
				tab[y][x++] = -1;
			else if (*(str - 1) == (*motif).empty)
				tab[y][x++] = 0;
			else
				return (ft_free_tab(tab, y));
		}
		if (*(str++) != '\n')
			return (ft_free_tab(tab, y));
		y++;
	}
	if (*str != '\0')
		return (ft_free_tab(tab, y - 1));
	return (tab);
}

int	**init_tab(char *str, t_motif *motif)
{
	int **tab;
	int	line_length;

	while (*str && *str != '\n')
		str++;
	str++;
	line_length = size_line(str);
	if (!line_length)
		return (0);
	if (!(tab = malloc((*motif).nb_lines * sizeof(int*))))
		return (0);
	tab = parse_fill_tab(tab, str, motif, line_length);
	return (tab);
}

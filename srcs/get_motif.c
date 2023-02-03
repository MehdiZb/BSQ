/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_motif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 08:53:36 by hthomas           #+#    #+#             */
/*   Updated: 2019/09/16 08:53:39 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	my_atoi(char *str, int max)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9' && i < max)
		nb = (nb * 10) + str[i++] - '0';
	if (i == 0)
		return (-1);
	return (nb);
}

int	size_line(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] != '\n' && str[size] != '\0')
		size++;
	return (size);
}

int	check_motif(t_motif *motif)
{
	if (is_printable((*motif).plain))
		return (0);
	if (is_printable((*motif).empty))
		return (0);
	if (is_printable((*motif).obstacle))
		return (0);
	if ((*motif).plain == (*motif).empty || (*motif).plain == (*motif).obstacle
		|| (*motif).empty == (*motif).obstacle)
		return (0);
	return (1);
}

int	first_line_valid(int lines_length, int size_first_line, t_motif *motif,
	char *str)
{
	int	i;
	int	nb_zeros;

	i = 0;
	nb_zeros = 0;
	while (i < size_first_line - 4 && str[i] == '0')
	{
		nb_zeros++;
		i++;
	}
	if (nb_zeros + lines_length + 3 != size_first_line || !check_motif(motif))
		return (0);
	return (1);
}

int	get_motif(char *str, t_motif *motif, t_square *size)
{
	int	i;
	int	lines;
	int	lines_length;
	int	size_first_line;

	size_first_line = size_line(str);
	i = 0;
	lines = my_atoi(str, size_first_line - 3);
	if (size_first_line < 4 || lines == -1)
		return (0);
	(*motif).nb_lines = lines;
	(*motif).plain = str[size_first_line - 1];
	(*motif).obstacle = str[size_first_line - 2];
	(*motif).empty = str[size_first_line - 3];
	(*size).ymax = lines;
	(*size).xmax = size_line(str + size_first_line + 1);
	lines_length = 0;
	while (lines)
	{
		lines_length++;
		lines /= 10;
	}
	if (!first_line_valid(lines_length, size_first_line, motif, str))
		return (0);
	return (1);
}

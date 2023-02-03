/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 08:37:00 by hthomas           #+#    #+#             */
/*   Updated: 2019/09/16 08:37:01 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_map_error(void)
{
	ft_putstr("map error\n");
	return (-1);
}

int	just_do_it(char *str)
{
	int			**tab;
	t_motif		motif;
	t_square	square;
	t_square	size;

	if (!get_motif(str, &motif, &size))
		return (ft_map_error());
	if (!(tab = init_tab(str, &motif)))
		return (ft_map_error());
	square = find_solution(tab, &size);
	print_solution(tab, &motif, &size, &square);
	ft_free_tab(tab, motif.nb_lines - 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int			i;
	char		*str;

	i = 1;
	if (argc == 1)
	{
		str = read_stdin();
		just_do_it(str);
		free(str);
		return (0);
	}
	while (i < argc)
	{
		str = open_file(argv[i]);
		just_do_it(str);
		if (i != argc - 1)
			ft_putchar('\n');
		i++;
		free(str);
	}
	return (0);
}

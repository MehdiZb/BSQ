/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:12:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/09/16 11:12:32 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BF_SIZE 10000

typedef	struct	s_motif
{
	int		nb_lines;
	char	plain;
	char	obstacle;
	char	empty;
}				t_motif;

typedef	struct	s_square
{
	int		xmin;
	int		ymin;
	int		xmax;
	int		ymax;
}				t_square;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
char			*ft_strcat(char *dest, char *src);
int				is_printable(char c);
char			*open_file(char *file);
char			*read_stdin();
int				get_motif(char *str, t_motif *motif, t_square *size);
int				size_line(char *str);
int				my_atoi(char *str, int max);
int				**malloc_tab_int(int **tab, t_square *size);
int				**ft_free_tab(int **tab, int y);
char			*malloc_file(char *file, int cpt);
char			*ft_strcat_malloc(char *src, char *buffer);
t_square		find_solution(int **tab_map, t_square *size);
int				**init_tab(char *str, t_motif *motif);
int				**parse_fill_tab(int **tab, char *str, t_motif *motif,
									int line_length);
void			print_solution(int **tab, t_motif *motif, t_square *size,
								t_square *square);

#endif

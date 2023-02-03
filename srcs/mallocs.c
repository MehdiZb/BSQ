/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:57:31 by hthomas           #+#    #+#             */
/*   Updated: 2019/09/18 09:57:33 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			**ft_free_tab(int **tab, int y)
{
	while (y >= 0)
		free(tab[y--]);
	free(tab);
	return (0);
}

char		*malloc_file(char *file, int cpt)
{
	char	*buffer;
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc((cpt + 1) * sizeof(char));
	ret = read(fd, buffer, cpt);
	buffer[ret] = '\0';
	if (close(fd) == -1)
		return (0);
	return (buffer);
}

char		*ft_strcat_malloc(char *src, char *buffer)
{
	char	*dest;

	dest = malloc((ft_strlen(src) + ft_strlen(buffer) + 1) * sizeof(char));
	dest[0] = '\0';
	ft_strcat(dest, src);
	ft_strcat(dest, buffer);
	free(src);
	src = dest;
	return (src);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 08:58:20 by hthomas           #+#    #+#             */
/*   Updated: 2019/09/16 08:58:22 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char		*open_file(char *file)
{
	char	tmp[100];
	int		fd;
	int		ret;
	int		cpt;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = 1;
	cpt = 0;
	while (ret)
	{
		ret = read(fd, tmp, 100);
		if (ret < 0)
			return (0);
		cpt += ret;
	}
	if (close(fd) == -1)
		return (0);
	if (cpt == 0)
		return (0);
	return (malloc_file(file, cpt));
}

char		*read_stdin(void)
{
	char	buffer[BF_SIZE + 1];
	char	*str;
	int		ret;

	if (!(str = malloc(sizeof(char) * 1)))
		return (0);
	str[0] = '\0';
	while ((ret = read(STDIN_FILENO, buffer, BF_SIZE)))
	{
		buffer[ret] = '\0';
		str = ft_strcat_malloc(str, buffer);
	}
	return (str);
}

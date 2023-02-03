/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:09:00 by hthomas           #+#    #+#             */
/*   Updated: 2019/08/28 20:09:00 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src, int start)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[start + i] = src[i];
		i++;
	}
	dest[start + i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	start;

	start = 0;
	while (dest[start])
		start++;
	return (ft_strcpy(dest, src, start));
}

int		is_printable(char c)
{
	if (!(c <= 126 && c >= 32))
		return (1);
	return (0);
}

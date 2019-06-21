/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:43:45 by ohelly            #+#    #+#             */
/*   Updated: 2019/03/25 21:38:22 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_full(char *arr, char *buf, char c)
{
	static int	i = 0;
	int			j;

	j = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == c)
		{
			while (buf[i] == c)
				i++;
			return (1);
		}
		arr[j] = buf[i];
		j++;
		i++;
	}
	return (1);
}

static int		ft_new_str(char **arr, char *buf, char c)
{
	static int		i = -1;
	int				j;
	int				count;

	j = -1;
	count = 0;
	while (buf[++i] != '\0')
	{
		count++;
		if (buf[i] == c && buf[i - 1] != c)
		{
			if (!(arr[++j] = (char*)ft_memalloc(sizeof(char) * count)))
				return (0);
			if (!(ft_full(arr[j], buf, c)))
				return (0);
			count = 0;
		}
		if ((buf[i] == c && buf[i - 1] == c) ||
		(buf[i] == c && buf[i + 1] == '\0'))
			return (1);
	}
	return (1);
}

static int		ft_count(char *buf, char c)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (buf[++i] != '\0')
		if ((buf[i] == c && buf[i - 1] == c) ||
		(buf[i] == c && buf[i + 1] == '\0'))
			count++;
	if (count == 0 || count > 26)
		return (-1);
	return (count);
}

char			***ft_split(char ***arr, char *buf, char c)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	j = -1;
	count = 0;
	if (!(arr = (char***)ft_memalloc(sizeof(char**) * (ft_count(buf, c) + 1))))
		return (0);
	while (buf[++i] != '\0')
	{
		if (buf[i] == c && buf[i - 1] != c)
			count++;
		if ((buf[i] == c && buf[i - 1] == c) ||
		(buf[i] == c && buf[i + 1] == '\0'))
		{
			if (!(arr[++j] = (char**)ft_memalloc(sizeof(char*) * (count + 1))))
				return (0);
			if (!(ft_new_str(arr[j], buf, c)))
				return (0);
			count = 0;
		}
	}
	return (arr);
}

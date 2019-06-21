/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:02:03 by ohelly            #+#    #+#             */
/*   Updated: 2019/03/24 20:55:50 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_checkstr(char *buf, char c)
{
	int		i;

	i = -1;
	if (buf[0] != '.' && buf[0] != '#')
	{
		ft_putendl("error");
		return (0);
	}
	while (buf[++i] != '\0')
	{
		if (buf[i] == c && buf[i - 1] == c && buf[i + 1] == '\0')
		{
			ft_putendl("error");
			return (0);
		}
	}
	if (buf[i] == '\0' && buf[i - 1] != '\n')
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

static int		ft_error(int ac, char **av, int fd)
{
	char	buf[1];

	if (ac != 2)
	{
		ft_putendl("usage: source_file");
		return (-1);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putendl("error");
		return (-1);
	}
	if (read(fd, buf, 0) < 0)
	{
		ft_putendl("error");
		return (-1);
	}
	return (fd);
}

static int		ft_checkonemore(char *buf, char c)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (buf[++i] != '\0')
	{
		if (buf[i] == c && buf[i + 1] != '\0')
			count++;
		if (buf[i] == c && count % 4 == 0)
		{
			if (buf[i + 1] != c && buf[i + 1] != '\0')
			{
				ft_putendl("error");
				return (0);
			}
			i++;
		}
	}
	if (count == 0)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

static int		ft_validcheck(char ***arr)
{
	int		i;

	i = -1;
	while (arr[++i])
	{
		if (!(ft_checkvalid(arr[i])))
		{
			ft_putendl("error");
			return (0);
		}
	}
	if (i > 26)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	char	***arr;
	char	buf[1500 + 1];
	int		fd;
	int		bytes;

	fd = 0;
	arr = 0;
	if ((fd = ft_error(ac, av, fd)) == -1)
		return (0);
	bytes = read(fd, buf, 1500);
	buf[bytes] = '\0';
	if (!(ft_checkstr(buf, '\n')))
		return (0);
	if (!(ft_checkonemore(buf, '\n')))
		return (0);
	if (!(arr = ft_split(arr, buf, '\n')))
		return (0);
	if (!(ft_validcheck(arr)))
		return (0);
	ft_minsquare(arr);
	close(fd);
	return (0);
}

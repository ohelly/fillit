/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minsquare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:12:44 by dtoy              #+#    #+#             */
/*   Updated: 2019/03/28 17:37:16 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_alphabet(char ***arr)
{
	int		i;
	int		j;
	int		x;
	char	a;

	i = 0;
	j = 0;
	x = -1;
	a = 'A';
	while (arr[i] != 0)
	{
		while (arr[i][j] != 0)
		{
			while (arr[i][j][++x] != '\0')
				if (arr[i][j][x] == '#')
					arr[i][j][x] = a;
			j++;
			x = -1;
		}
		i++;
		a++;
		j = 0;
	}
}

static char		**ft_createsquare(int insquare)
{
	char	**res;
	int		i;

	i = 0;
	res = (char**)ft_memalloc(sizeof(char*) * (insquare + 1));
	while (i < insquare)
	{
		res[i] = (char*)ft_memalloc(sizeof(char) * insquare + 1);
		ft_memset(res[i], '.', insquare);
		res[i][insquare] = '\0';
		i++;
	}
	res[i] = 0;
	return (res);
}

static int		ft_findsquare(int count)
{
	int		res;
	int		a;

	a = 2;
	res = 0;
	while (res < count)
	{
		res = a * a;
		a++;
	}
	return (--a);
}

static int		ft_countsquare(char **block, int count)
{
	int		i;
	int		j;

	i = 0;
	while (block[i])
	{
		j = 0;
		while (block[i][j])
		{
			if (block[i][j] == '#')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int				ft_minsquare(char ***block)
{
	int		z;
	int		count;
	int		insquare;
	char	**min;

	count = 0;
	z = 0;
	while (block[z])
	{
		count = ft_countsquare(block[z], count);
		z++;
	}
	insquare = ft_findsquare(count);
	min = ft_createsquare(insquare);
	block = ft_moveblock(block);
	ft_alphabet(block);
	ft_start(block, min);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvesquare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:55:49 by dtoy              #+#    #+#             */
/*   Updated: 2019/03/28 18:58:53 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_other(char **min, int i, int j, int len)
{
	if (i > len)
		return (-1);
	if (j > len)
		return (-2);
	if (i == len)
		return (-3);
	if (min[i][j] != '.')
		return (0);
	else
		return (1);
}

int		ft_compare(char **block, char **min, int x, int y)
{
	int		i;
	int		j;
	int		res;

	res = 0;
	i = -1;
	while (block[++i])
	{
		j = -1;
		while (block[i][++j])
		{
			if (block[i][j] >= 'A' && block[i][j] <= 'Z')
			{
				res = ft_other(min, i + y, j + x, (int)ft_strlen(min[0]));
				if (res <= 0 && res >= -3)
					return (res);
			}
		}
	}
	return (1);
}

int		ft_takein(char **block, char **min, int *x, int *y)
{
	int		i;
	int		j;

	i = 0;
	while (block[i])
	{
		j = 0;
		while (block[i][j])
		{
			if (block[i][j] >= 'A' && block[i][j] <= 'Z')
				min[i + *y][j + *x] = block[i][j];
			j++;
		}
		i++;
	}
	*y = 0;
	*x = 0;
	return (1);
}

int		ft_doesntfill(int res, int *x, int *y)
{
	if (ft_counter() == -1)
		return (0);
	if (res == 0)
		*x += 1;
	else if (res == -1)
	{
		*x += 1;
		*y = 0;
	}
	else if (res == -2)
	{
		*x = 0;
		*y += 1;
	}
	return (1);
}

int		ft_solvesquare(char ***block, char **min, int z, int bc)
{
	int		res;
	int		x;
	int		y;

	while (block[z])
	{
		res = 0;
		x = 0 + bc % 100;
		y = 0 + bc / 100;
		while (res != 1)
		{
			if ((res = ft_compare(block[z], min, x, y)) == 1)
				ft_takein(block[z++], min, &x, &y);
			else if (res >= -2 && res <= 0)
				if (ft_doesntfill(res, &x, &y) == 0)
					return (0);
			if (res == -3 && z == 0)
				return (-1);
			else if (res == -3)
				return (ft_solvesquare2(block, min, z, bc));
		}
		bc = 0;
	}
	return (1);
}

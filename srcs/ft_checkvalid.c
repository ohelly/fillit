/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:11:34 by dtoy              #+#    #+#             */
/*   Updated: 2019/03/28 17:37:44 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_i(char **block, int i, int j, int t)
{
	if (i == 3)
	{
		if (block[i - 1][j] == '#')
			t++;
		if (block[i][j + 1] == '#')
			t++;
		if (block[i][j - 1] == '#')
			t++;
	}
	else if (i == 0)
	{
		if (block[i + 1][j] == '#')
			t++;
		if (block[i][j + 1] == '#')
			t++;
		if (block[i][j - 1] == '#')
			t++;
	}
	return (t);
}

static int		ft_check_j(char **block, int i, int j, int t)
{
	if (j == 0)
	{
		if (block[i + 1][j] == '#')
			t++;
		if (block[i - 1][j] == '#')
			t++;
		if (block[i][j + 1] == '#')
			t++;
	}
	else if (j == 3)
	{
		if (block[i + 1][j] == '#')
			t++;
		if (block[i - 1][j] == '#')
			t++;
		if (block[i][j - 1] == '#')
			t++;
	}
	return (t);
}

static int		ft_checkall(char **block, int i, int j, int t)
{
	if (block[i][j] == '#' || block[i][j] == '.')
	{
		if (block[i][j] == '#')
		{
			if ((i != 3 && i != 0) && (j != 0 && j != 3))
			{
				if (block[i][j + 1] == '#')
					t++;
				if (block[i][j - 1] == '#')
					t++;
				if (block[i + 1][j] == '#')
					t++;
				if (block[i - 1][j] == '#')
					t++;
			}
			else if (i == 3 || i == 0)
				t = ft_check_i(block, i, j, t);
			else if (j == 0 || j == 3)
				t = ft_check_j(block, i, j, t);
		}
	}
	else
		return (-1);
	return (t);
}

int				ft_checkvalid(char **block)
{
	int		count;
	int		i;
	int		j;
	int		t;

	count = 0;
	t = 0;
	i = -1;
	while (block[++i])
	{
		j = 0;
		while (block[i][j])
		{
			if (block[i][j] == '#')
				count++;
			if ((t = ft_checkall(block, i, j, t)) == -1)
				return (0);
			j++;
		}
		if (j != 4)
			return (0);
	}
	if (i != 4 || t < 6 || t > 8 || count != 4)
		return (0);
	return (1);
}

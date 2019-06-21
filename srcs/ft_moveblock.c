/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveblock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:12:48 by dtoy              #+#    #+#             */
/*   Updated: 2019/03/24 20:01:17 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_checkblocki(char **block)
{
	int		i;

	i = 0;
	while (block[i])
	{
		if (*block[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_checkblockj(char **block)
{
	int		j;

	j = 0;
	while (block[0][j])
	{
		if (block[0][j] == '#')
			return (1);
		j++;
	}
	return (0);
}

static char		**ft_moveblockleft(char **block)
{
	int		i;
	int		j;

	i = 0;
	if (ft_checkblocki(block))
		return (block);
	while (block[i])
	{
		j = 0;
		while (block[i][j])
		{
			if (block[i][j] == '#' && j > 0)
			{
				block[i][j - 1] = '#';
				block[i][j] = '.';
			}
			j++;
		}
		i++;
	}
	return (ft_moveblockleft(block));
}

static char		**ft_moveblockup(char **block)
{
	int		i;
	int		j;

	if (ft_checkblockj(block))
		return (block);
	i = 0;
	while (block[i])
	{
		j = 0;
		while (block[i][j])
		{
			if (block[i][j] == '#' && i > 0)
			{
				block[i - 1][j] = '#';
				block[i][j] = '.';
			}
			j++;
		}
		i++;
	}
	return (ft_moveblockup(block));
}

char			***ft_moveblock(char ***block)
{
	int		z;

	z = 0;
	while (block[z])
	{
		block[z] = ft_moveblockleft(block[z]);
		block[z] = ft_moveblockup(block[z]);
		z++;
	}
	return (block);
}

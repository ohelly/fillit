/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastletter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:49:19 by dtoy              #+#    #+#             */
/*   Updated: 2019/03/28 17:37:23 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check(char ***block, char tmp)
{
	int		z;
	int		i;
	int		j;

	z = 0;
	while (block[z])
	{
		i = 0;
		while (block[z][i])
		{
			j = 0;
			while (block[z][i][j])
			{
				if (block[z][i][j] == tmp)
					return (z + 1);
				j++;
			}
			i++;
		}
		z++;
	}
	return (0);
}

int				ft_lastletter(char ***block, char **min)
{
	char	tmp;
	int		i;
	int		j;

	tmp = 0;
	i = 0;
	while (min[i])
	{
		j = 0;
		while (min[i][j])
		{
			if (min[i][j] > tmp)
				tmp = min[i][j];
			j++;
		}
		i++;
	}
	return (ft_check(block, tmp));
}

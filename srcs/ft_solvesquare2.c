/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvesquare2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:30:36 by dtoy              #+#    #+#             */
/*   Updated: 2019/03/28 18:56:05 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_dotall(char **min, char let)
{
	int		i;
	int		j;

	i = 0;
	while (min[i])
	{
		j = 0;
		while (min[i][j])
		{
			if (min[i][j] == let)
				min[i][j] = '.';
			j++;
		}
		i++;
	}
}

static char		ft_letter(char **block)
{
	int		i;
	int		j;

	i = 0;
	while (block[i])
	{
		j = 0;
		while (block[i][j])
		{
			if (block[i][j] != '.' && block[i][j] != '\0')
				return (block[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

static int		ft_before(char **block)
{
	int		j;

	j = 0;
	while (block[0][j] == '.')
		j++;
	return (j);
}

static void		ft_retbc(char **min, char **block, char let, int *bc)
{
	int		i;
	int		j;

	i = 0;
	while (min[i])
	{
		j = 0;
		while (min[i][j])
		{
			if (min[i][j] == let)
			{
				j = j - ft_before(block) + 1;
				*bc = i * 100 + j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int				ft_solvesquare2(char ***block, char **min, int z, int bc)
{
	ft_retbc(min, block[z - 1], ft_letter(block[z - 1]), &bc);
	ft_dotall(min, ft_letter(block[z - 1]));
	return (ft_solvesquare(block, min, z - 1, bc));
}

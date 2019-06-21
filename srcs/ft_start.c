/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 21:35:50 by dtoy              #+#    #+#             */
/*   Updated: 2019/03/28 17:36:42 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_start(char ***block, char **min)
{
	int		z;
	int		res;

	z = 0;
	while ((res = ft_solvesquare(block, min, z, 0)) <= 0)
	{
		if (res == -1)
		{
			min = ft_newsqr(min, (int)ft_strlen(min[0]));
			z = 0;
		}
		else
			z = ft_lastletter(block, min);
	}
	ft_output(min, block);
	return (1);
}

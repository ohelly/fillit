/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:45:11 by dtoy              #+#    #+#             */
/*   Updated: 2019/03/28 17:37:03 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_delblock(char ***block)
{
	int		z;

	z = 0;
	while (block[z])
		ft_del(block[z++]);
	free(block);
	block = 0;
}

void			ft_output(char **min, char ***block)
{
	int		i;

	i = 0;
	while (min[i])
	{
		ft_putendl(min[i]);
		i++;
	}
	ft_del(min);
	ft_delblock(block);
}

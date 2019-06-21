/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsqr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:59:31 by ohelly            #+#    #+#             */
/*   Updated: 2019/03/28 17:37:09 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_createsquare1(int insquare)
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

char			**ft_newsqr(char **min, int len)
{
	ft_del(min);
	min = ft_createsquare1(len + 1);
	return (min);
}

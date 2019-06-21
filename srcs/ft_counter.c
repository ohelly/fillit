/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:45:52 by dtoy              #+#    #+#             */
/*   Updated: 2019/03/28 17:37:35 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_counter(void)
{
	static int	count = 0;

	count++;
	if (count == 10000)
	{
		count = 0;
		return (-1);
	}
	return (1);
}
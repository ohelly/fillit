/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:08:22 by ohelly            #+#    #+#             */
/*   Updated: 2019/03/25 21:42:04 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

char	***ft_split(char ***arr, char *buf, char c);
int		ft_checkvalid(char **block);
int		ft_minsquare(char ***block);
char	***ft_moveblock(char ***block);
int		ft_solvesquare(char ***block, char **min, int z, int bc);
int		ft_solvesquare2(char ***block, char **min, int z, int bc);
char	**ft_newsqr(char **min, int len);
int		ft_counter(void);
void	ft_output(char **min, char ***block);
void	ft_del(char **min);
int		ft_lastletter(char ***block, char **min);
int		ft_start(char ***block, char **min);

#endif

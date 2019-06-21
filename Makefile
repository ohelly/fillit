# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 18:08:53 by ohelly            #+#    #+#              #
#    Updated: 2019/03/28 17:36:26 by ohelly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = 	srcs/main.c \
	srcs/ft_checkvalid.c \
	srcs/ft_split.c \
	srcs/ft_minsquare.c \
	srcs/ft_moveblock.c \
	srcs/ft_solvesquare.c \
	srcs/ft_solvesquare2.c \
	srcs/ft_newsqr.c \
	srcs/ft_output.c \
	srcs/ft_counter.c \
	srcs/ft_lastletter.c \
	srcs/ft_del.c \
	srcs/ft_start.c
OBJ = $(SRCS:%.c=%.o)
LIBPATH = libft
LIBINC = libft/includes
INC = includes
LIBFT = -lm -L$(LIBPATH) -lft
INCLUDES = -I$(INC) -I$(LIBINC)
all: $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBPATH)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)
%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
clean:
	make -C $(LIBPATH) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBPATH) fclean
	rm -rf $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 16:30:21 by tgmelin           #+#    #+#              #
#    Updated: 2024/08/03 23:02:00 by tgmelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g
SRC  = ft_arrlen.c ft_freeptrarr.c ft_memcpy.c ft_strlen.c ft_atoi.c lst_utils.c lst_utils2.c main.c ps_instr_a.c ps_instr_b.c ps_instr_c.c predefined.c predefined_algos_a.c predefined_algos_b.c predefined_algos_c.c predefined_algos_d.c predefined_algos_e.c predefined_algos_f.c predefined_algos_g.c quicksort.c quicksort_utils.c permutations.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
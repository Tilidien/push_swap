# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgmelin <tgmelin@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 16:30:21 by tgmelin           #+#    #+#              #
#    Updated: 2024/08/03 22:56:10 by tgmelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CFLAGS = -Wall -Wextra -Werror -g
SRC  = ps_instr_c.c get_next_line.c get_next_line_utils.c lst_utils.c main.c ps_instr_a.c ps_instr_b.c lst_utils2.c utils.c ft_atoi.c instructions.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
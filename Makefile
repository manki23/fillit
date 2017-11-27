# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:15:29 by lguiller          #+#    #+#              #
#    Updated: 2017/11/26 10:14:02 by manki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_EXE = fillit

NAME_H = fillit.a

SRC = srcs/main.c srcs/ft_stock_and_check_file.c \
	  srcs/ft_split_rec_tetri.c srcs/ft_nb.c \
	  srcs/ft_solve_grid.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME_H)

$(NAME_H): $(OBJ)
	@echo "Creation de libft.a 😎"
	@make -C libft all
	@echo "Creation de fillit.a 😎"
	@ar rc $(NAME_H) $(OBJ)
	@ranlib $(NAME_H)
	@echo "Creation de fillit 😎"
	@gcc $(FLAGS) $(LIBFT) $(OBJ) -o $(NAME_EXE)

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@

clean:
	@echo "Suppression des *.o 😱"
	@make -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "Suppression de libft.a 😱"
	@echo "Suppression de fillit.a 😱"
	@echo "Suppression de fillit 😱"
	@make -C libft fclean
	@/bin/rm -f $(NAME_EXE) $(NAME_H)

re: fclean all

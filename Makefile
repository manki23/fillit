# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:15:29 by lguiller          #+#    #+#              #
#    Updated: 2017/12/29 12:38:35 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME	= fillit

SRC 	= srcs/fillit.c srcs/ft_stock_and_check_file.c srcs/ft_list_function.c \
		  srcs/ft_record_tetris.c srcs/ft_resolve_grid.c \
		  srcs/ft_recursive_solve_grid.c \

FLAGS 	= -Wall -Wextra -Werror

##################
##    COLORS    ##
##################

_GREY	=	$ \033[30m
_RED	=	$ \033[31m
_GREEN	=	$ \033[32m
_YELLOW	=	$ \033[33m
_BLUE	=	$ \033[34m
_PURPLE	=	$ \033[35m
_CYAN	=	$ \033[36m
_WHITE	=	$ \033[37m
_END	=	$ \033[0m

##################
##   TARGETS    ##
##################

.PHONY: all clean

all: $(NAME)

$(NAME): $(OBJ)
	@echo "✅	$(_GREEN)Creation	libft.a	😎$(_END)"
	@make -C libft all
	@echo "✅	$(_GREEN)Creation	fillit	😎$(_END)"
	@gcc $(FLAGS) $(SRC) ./libft/libft.a -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@

clean:
	@echo "❌	$(_RED)Suppression	*.o	😱$(_END)"
	@make -C libft clean

fclean: clean
	@echo "❌	$(_RED)Suppression	libft.a	😱$(_END)"
	@make -C libft fclean
	@echo "❌	$(_RED)Suppression	fillit	😱$(_END)"
	@/bin/rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 13:47:41 by ikovalen          #+#    #+#              #
#    Updated: 2018/12/06 14:02:22 by ikovalen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -c -Wall -Wextra -Werror
OBJ = *.o

all: $(NAME)

$(NAME):
	@make -C libft
	gcc $(FLAGS) *.c	
	ar rc $(NAME) *.o libft/*.o

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all	

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zskeeter <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 18:40:15 by zskeeter          #+#    #+#              #
#    Updated: 2021/01/26 22:06:29 by zskeeter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =	printf.c utils.c \
		printers/print_d.c printers/print_c.c

SRCOBJS = $(SRCS:.c=.o)

$(NAME): $(SRCOBJS) printf.h
	make -C libft
	ar -rcs $(NAME) $(SRCOBJS) libft/*.o

all: $(NAME)

clean : 
		rm -rf $(SRCOBJS) 
		make -C libft/ clean

fclean : clean
		make -C libft/ fclean
		rm -rf $(NAME)

re :  fclean all 

d:
	gcc -Wall -Wextra -Werror -g printf.c atoi.c print_d.c

t: fclean all
	gcc -Wall -Wextra -Werror -g main.c libftprintf.a
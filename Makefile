# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 18:40:15 by zskeeter          #+#    #+#              #
#    Updated: 2021/01/30 01:01:25 by zskeeter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Filenames
NAME = libftprintf.a
SRC = printf.c utils.c
HANDLER_FILES = print_d.c print_c.c print_s.c print_p.c print_x.c print_u.c

# Directories
HANDLERS_DIR = handlers
LIBFT = libft
OBJs_DIR = objects

# Preparing
HANDLERS = $(patsubst %, $(HANDLERS_DIR)/%, $(HANDLER_FILES))
OBJS = $(patsubst %, $(OBJs_DIR)/%.o, $(SRC) $(HANDLERS))

SRCOBJS = $(SRCS:.c=./objects/.o)

$(NAME): $(OBJS) printf.h
	make -C libft
	ar -rcs $(NAME) $(OBJS) libft/*.o

all: $(NAME)

pr:
	echo $(HANDLERS)
	echo $(OBJS)

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

dbg: fclean
	gcc -Wall -Wextra -Werror -g main.c $(SRCS) libft/ft_itoa.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_substr.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c
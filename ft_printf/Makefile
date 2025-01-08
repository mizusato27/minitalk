# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 15:16:46 by mizusato          #+#    #+#              #
#    Updated: 2025/01/08 18:58:48 by mizusato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = libftprintf.a

CC         = cc
CFLAGS     = -Wall -Wextra -Werror

HDRS       = ft_printf.h
SRCS       = ft_print_char.c ft_print_number.c ft_print_pointer.c ft_printf.c ft_putnbr.c
OBJS       = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

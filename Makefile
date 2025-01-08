# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 20:21:25 by mizusato          #+#    #+#              #
#    Updated: 2025/01/08 20:58:14 by mizusato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC     = cc
CFLAGS = -Wall -Wextra -Werror

HDRS   = minitalk.h
SRCS_S = server.c
OBJS_S = $(SRCS_S:.c=.o)
SRCS_C = client.c
OBJS_C = $(SRCS_C:.c=.o)

PRINTF = ft_printf/libftprintf.a

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_S) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_S) $(PRINTF) -o $(SERVER)

$(CLIENT): $(OBJS_C) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_C) $(PRINTF) -o $(CLIENT)

$(PRINTF):
	$(MAKE) -C ft_printf

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS_S) $(OBJS_C)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re

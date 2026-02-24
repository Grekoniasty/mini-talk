# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/09 13:51:07 by mpiasecz          #+#    #+#              #
#    Updated: 2025/10/09 13:51:26 by mpiasecz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = server.c
SRCC = client.c

OBJS = $(SRCS:.c=.o)
OBJC = $(SRCC:.c=.o)

PRINTF_DIR = Printf
LIBFT_DIR = libft

PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) minitalk.h
	@echo "Creating server..."
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) -o $(SERVER)

$(CLIENT): $(OBJC) $(PRINTF_LIB) $(LIBFT_LIB) minitalk.h
	@echo "Creating client..."
	$(CC) $(CFLAGS) $(OBJC) $(PRINTF_LIB) $(LIBFT_LIB) -o $(CLIENT)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR) --no-print-directory


$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) --no-print-directory


%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJC)
	@make -C $(PRINTF_DIR) --no-print-directory clean
	@make -C $(LIBFT_DIR) --no-print-directory clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	@make -C $(PRINTF_DIR) --no-print-directory fclean
	@make -C $(LIBFT_DIR) --no-print-directory fclean

# Rebuild all
re: fclean all

.PHONY: all clean fclean re

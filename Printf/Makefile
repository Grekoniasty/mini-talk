NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = ft_printf.c ft_putnbr.c ft_putstr.c ft_putnbr_base.c ft_putnbr_u.c ft_str_filler.c ft_printchr.c ft_pointer.c ft_hexa_stuff.c ft_helper.c ft_printchrnum.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus

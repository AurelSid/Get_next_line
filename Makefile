NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_print_to_print.c  ft_putchar.c ft_putnbr_base.c ft_putptr_base.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_putunbr.c


OBJ = $(SRC:.c=.o)


AR = ar -rc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
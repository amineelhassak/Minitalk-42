SRC = ft_putstr.c ft_printf.c ft_strlen.c ft_putnbr.c ft_convert.c ft_putc.c ft_putu.c ft_putp.c
OBJS = $(SRC:.c=.o)
NAME = libftprintf.a

CFLAGSCC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c  ft_printf.h
	$(CFLAGSCC) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

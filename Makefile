NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = 	./src/ft_printf.c \
		./utils/utils.c \
		./utils/ft_hexa.c \
		./utils/ft_hexaptr.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I./headers -o $@ -c $^

make: make all

bonus:	$(OBJ) $(OBJBONUS)
		ar rcs $(NAME) $(OBJ) $(OBJBONUS)

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = 	./src/printf.c \
		./utils/utils.c \
		./utils/utils2.c \
		./utils/ft_puthexa.c \

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

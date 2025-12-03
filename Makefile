CC = cc

FLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = 	main.c \
		construct.c \
		parse_input.c  \
		output.c \
		push.c \
		swap.c \
		reverse.c \
		stack_functions.c

OBJ = $(SRC:.c=.o)

LIB = libft.a libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o push_swap

clean:
	rm *.o

fclean: clean
	rm $(NAME);

re: fclean all

.PHONY: all clean fclean re
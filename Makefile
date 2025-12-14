CC = gcc

FLAGS = -g -O0 -Wall -Werror -Wextra

NAME = push_swap

SRC = \
		calculations.c \
		checks.c \
		construct.c \
		main.c \
		output.c \
		push.c \
		push_swap.c \
		rotate.c \
		simple_sort.c \
		stack_functions.c \
		swap.c \
		utils.c

OBJ = $(SRC:.c=.o)

LIB = libft.a libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o push_swap

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm *.o

fclean: clean
	rm $(NAME);

re: fclean all

.PHONY: all clean fclean re
NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = \
	src/main.c \
	src/push_swap.c \
	src/helpers//calculations.c \
	src/helpers/parse_input.c \
	src/operations/push.c \
	src/operations/rotate.c \
	src/operations/swap.c \
	src/operations/stack.c \
	src/operations/utils.c \
	mini_libft/ft_atoi.c \
	mini_libft/ft_split.c \
	mini_libft/ft_isdigit.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_putnbr_base.c \
	ft_printf/ft_str_f.c \
	ft_printf/ft_wrappers.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building your push_swap executable..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f src/*.o
	@rm -f src/helpers/*.o
	@rm -f src/operations/*.o
	@rm -f mini_libft/*.o
	@rm -f ft_printf/*.o


fclean: clean
	@rm -f $(NAME)

re: fclean all clean 
NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = \
	src/main.c \
	src/calculations.c \
	src/parse_input.c \
	src/push.c \
	src/push_swap.c \
	src/rotate.c \
	src/swap.c \
	src/stack.c \
	src/utils.c \
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
	@rm -rf *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all clean 
NAME = push_swap

BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = \
		src/main.c \
		src/push_swap.c \
		src/helpers/calculations.c \
		src/helpers/input_checks.c \
		src/helpers/parse_input.c \
		src/operations/push.c \
		src/operations/rotate.c \
		src/operations/swap.c \
		src/operations/stack.c \
		src/operations/utils.c \
		mini_libft/ft_atol.c \
		mini_libft/ft_split.c \
		mini_libft/ft_isdigit.c \
		mini_libft/ft_strcmp.c \
		mini_libft/ft_putstr_fd.c \
		mini_libft/ft_strlen.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_putnbr_base.c \
		ft_printf/ft_str_f.c \
		ft_printf/ft_wrappers.c

BONUS_SRC = \
		src/helpers/calculations.c \
		src/helpers/input_checks.c \
		src/helpers/parse_input.c \
		src/operations/push.c \
		src/operations/rotate.c \
		src/operations/swap.c \
		src/operations/stack.c \
		src/operations/utils.c \
		mini_libft/ft_atol.c \
		mini_libft/ft_split.c \
		mini_libft/ft_isdigit.c \
		mini_libft/ft_strlen.c \
		mini_libft/ft_strcmp.c \
		mini_libft/ft_putstr_fd.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_putnbr_base.c \
		ft_printf/ft_str_f.c \
		ft_printf/ft_wrappers.c \
		bonus_src/get_next_line.c \
		bonus_src/get_next_line_utils.c \
		bonus_src/checker.c


OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ)
	@echo "Building your push_swap executable..."
	@$(CC) $(CFLAGS) $^ -o $@

$(BONUS): $(BONUS_SRC)
	@echo "Building your checker executable..."
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f src/*.o
	@rm -f src/helpers/*.o
	@rm -f src/operations/*.o
	@rm -f bonus_src/*.o
	@rm -f mini_libft/*.o
	@rm -f ft_printf/*.o


fclean: clean
	@rm -f $(BONUS)
	@rm -f $(NAME)

re: fclean all clean 
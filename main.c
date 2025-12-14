#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	a = check_input(argc, argv);
	b = create_stack();
	if (!a)
	{
		ft_printf("Error\n");
		free_all(&a, &b);
		return (0);
	}
	if (!is_sorted(a))
	{
		if (a->size <= 3)
			sort_three(a);
		else
			push_swap(a, b);
	}
	// if (is_sorted(a))
	// 	ft_printf("SORTED!!!\n");
	free_all(&a, &b);
	return (0);
}

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc == 1)
		return (0);
	
	a = check_input(argc, argv);
	b = create_stack();
	if (!a)
	{
		ft_printf("ERROR\n");
		free_stack(&b);
		return (0);
	}
	ft_printf("size = %d\n", a->size);
	test(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
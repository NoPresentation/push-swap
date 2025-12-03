#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;

	if (argc == 1)
		return (0);
	
	a = check_input(argc, argv);
	if (!a)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	print_stack(a);
	ft_printf("size = %d\n", a->size);
	free_stack(&a);
	return (0);
}
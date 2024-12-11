#include "push_swap.h"

static void	algo42(t_data *data)
{
	ft_printf("# + ALGO42 SELECTED! +\n");				// remove me
	ft_printf("# [0] BEFORE ALGO42: %i\n", data->a[0].num);		// remove me
	ft_printf("# [1] BEFORE ALGO42: %i\n", data->a[1].num);		// remove me
	if (data->a[0].num > data->a[1].num)
		swap_a(data);
	ft_printf("# [0] AFTER ALGO42: %i\n", data->a[0].num);		// remove me
	ft_printf("# [1] AFTER ALGO42: %i\n", data->a[1].num);		// remove me
}

void	select_algo(t_data *data)
{
	if (data->size == 2)
		algo42(data);
}

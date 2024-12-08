#include "push_swap.h"

static void	algo42(t_data *data)
{
	int	tmp;

	ft_printf("# [0] BEFORE ALGO42: %i\n", data->a[0].num);
	ft_printf("# [1] BEFORE ALGO42: %i\n", data->a[1].num);
	if (data->a[0].num > data->a[1].num)
	{
		tmp = data->a[0].num;
		data->a[0].num = data->a[1].num;
		data->a[1].num = tmp;
	}
	ft_printf("# [0] AFTER ALGO42: %i\n", data->a[0].num);
	ft_printf("# [1] AFTER ALGO42: %i\n", data->a[1].num);
}

void	select_algo(t_data *data)
{
	if (data->size == 2)
		algo42(data);
}

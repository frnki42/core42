#include "libft/get_next_line/get_next_line.h"
#include "libft/printf/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

int	main()
{
	int	file;
	int	count;
	char	*output;

	file = open("maps/map_valid.ber", 0_RDONLY);
	if (file == -1)
	{
		ft_printf("ERROR OPENING MAP!\n");
		return (1);
	}
	output = get_next_line(file);
	while
	{
		count = ft_printf("%s", output);
		ft_printf("\n");
		ft_printf("%d bytes were written\n", count);
		free(output);
		output = get_next_line(file);
	}
	if (count == 0)
		ft_printf("NO MORE LINES TO READ.\n");
	free(output);
	close(file);
	return (0);
}

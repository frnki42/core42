#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;

	i = 7;
	while (i >= 0)
		(octet & (1 << i--)) ? write(1, "1", 1) : write(1, "0", 1);
}
/*
int	main(void)
{
	print_bits(2);
	return (0);
}*/

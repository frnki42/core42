unsigned char	swap_bits(unsigned char c)
{
	return (c << 4 | c >> 4);
}
/*
#include <stdio.h>

int	main()
{
	unsigned char c = 149;
	printf("%c\n", swap_bits(c));
	return (0);
}*/

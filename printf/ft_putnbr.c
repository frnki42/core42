#include <unistd.h>

int	ft_putnbr(int n, int count)
{
	char	temp;
	long	nlong;

	nlong = n;
	if(nlong < 0)
	{
		if(write(1, "-", 1) == -1)
			return (-1);
		count++;
		nlong = -nlong;
	}
	if (nlong > 9)
		count = ft_putnbr(nlong / 10, count);
	temp = (nlong % 10) + '0';
	if(write(1, &temp, 1) == -1)
		return (-1);
	return (++count);
}

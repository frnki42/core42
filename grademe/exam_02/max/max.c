int	max(int* tab, unsigned int len)
{
	int		number;
	unsigned int	i;

	if (!tab[0] || len == 0 || !tab)
		return (0);
	number = 0;
	i = 0;
	while(i < len)
	{
		if (number < tab[i])
			number = tab[i];
		i++;
	}
	return (number);
}
/*
#include <stdio.h>

int	main(void)
{
	int	result;
	int	tab[9];
	int	empty[1];

	tab[0] = 42;
	tab[1] = 875;
	tab[2] = 1337;		//assign tab
	tab[3] = 69;
	tab[4] = 4;
	tab[5] = 2;
	tab[6] = 4242;		//assign tab
	tab[7] = 567;
	tab[8] = '\0';

	empty[0] = '\0';	//assign empty


		//print tab with len++
	result = max(tab, 1);
	printf("1:%i\n", result);

	result = max(tab, 2);
	printf("2:%i\n", result);

	result = max(tab, 3);
	printf("3:%i\n", result);

	result = max(tab, 4);
	printf("4:%i\n", result);

	result = max(tab, 5);
	printf("5:%i\n", result);

	result = max(tab, 6);
	printf("6:%i\n", result);

	result = max(tab, 7);
	printf("7:%i\n", result);

	result = max(tab, 8);
	printf("8:%i\n", result);

	result = max(empty, 1);
	printf("%i\n", result);
	return (0);
}*/

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	count;
	size_t	i;

	count = 0;
	while (s[count])
	{
		i = 0;
		while (reject[i])
		{
			if (s[count] == reject[i])
				return (count);
			i++;
		}
		count++;
	}
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s;
	const char	*reject;
	size_t		result;
	
	result = 0;
	s = "This is the test string we are traversiXgn to find the reject!";
	reject = "X";
	result = ft_strcspn(s, reject);
	printf("The result is: %ld\n", result);
	return (0);
}*/

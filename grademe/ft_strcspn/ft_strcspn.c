#include <unistd.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
	{
		i = 0;
		while (reject[i])
		{
			if (s[len] == reject[i++])
				return (len);
		}
		len++;
	}
	return (len);
}
/*
int	main(int argc, char **argv)
{
	int	len;

	if (argc != 3)
		return (write(1, "kekW n00b!\n", 11));
	len = 42;
	printf("len = %i (should be 42)\n", len);
	len = ft_strcspn(argv[1], argv[2]);
	printf("len after ft_strcpsn exec: %i\n", len);
	return (0);
}*/

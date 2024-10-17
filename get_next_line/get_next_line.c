#include "get_next_line.h"

char	*read_file(int fd, char *rest)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(rest, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	free(buffer);
	return (rest);
}

char	*get_line(char *rest)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_rest(char *rest)
{
	size_t		i;
	size_t		j;
	char	*new_rest;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	new_rest = malloc(ft_strlen(rest) - i + 1);
	if (!new_rest)
		return (NULL);
	i++;
	j = 0;
	while (rest[i])
		new_rest[j++] = rest[i++];
	new_rest[j] = '\0';
	free(rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = read_file(fd, rest);
	if (!rest)
		return (NULL);
	line = get_line(rest);
	rest = update_rest(rest);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		file;
	int		count;
	char	*output;

	file = open("file.txt", O_RDONLY);
	if (file == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%dTH OUTPUT:\n", i + 1);
		output = get_next_line(file);
		if (output)
		{
			count = printf("%s", output);
			printf("\n%d bytes were written\n", count);
			free(output);
		}
		else
		{
			printf("No more lines to read.\n");
			break;
		}
	}
	close(file);
	return (0);
}

#include "get_next_line.h"

// Function to join rest and buffer
char	*read_and_join(int fd, char *rest)
{
	char	*buffer;
	char	*joined;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0) // Handle read errors or end of file
	{
		free(buffer);
		if (bytes < 0)
			return (NULL); // Return NULL on error
		return (rest); // Return the remaining rest if EOF is reached
	}
	buffer[bytes] = '\0'; // Null-terminate buffer
	joined = ft_strjoin(rest, buffer); // Join buffer with rest
	free(rest); // Free old rest
	free(buffer); // Free buffer
	return (joined); // Return the newly joined string
}

// Function to extract the line up to and including '\n'
char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n') // Allocate memory for newline
		line = malloc(i + 2); // i chars + 1 for '\n' + 1 for '\0'
	else
		line = malloc(i + 1); // i chars + 1 for '\0'
	if (!line)
		return (NULL);
	for (size_t j = 0; j < i; j++) // Copy buffer content into line
		line[j] = buffer[j];
	if (buffer[i] == '\n')
		line[i++] = '\n'; // Add newline if present
	line[i] = '\0'; // Null-terminate the line
	return (line);
}

// Function to update rest with the content after the '\n'
char	*update_rest(char *buffer)
{
	size_t	i = 0;
	char	*rest;

	while (buffer[i] && buffer[i] != '\n') // Find the newline
		i++;
	if (!buffer[i]) // If no newline is found, return NULL
		return (NULL);
	rest = ft_strjoin("", buffer + i + 1); // Allocate and copy everything after '\n'
	return (rest);
}

// Main get_next_line function
char	*get_next_line(int fd)
{
	static char	*rest = NULL; // Keep track of leftover data
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rest = read_and_join(fd, rest); // Join rest with newly read data
	if (!rest) // If read_and_join failed or returned NULL
		return (NULL);
	line = extract_line(rest); // Extract the line to return
	rest = update_rest(rest); // Update rest for the next call

	return (line); // Return the extracted line
}

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	file;
	int	count;
	char	*output;

	file = open("file.txt", O_RDONLY);
	for (int i = 0; i < 7; i++) // Test multiple lines
	{
		printf("%dTH OUTPUT:\n", i + 1);
		output = get_next_line(file);
		if (output) // Check if output is NULL
		{
			count = printf("%s", output);
			printf("\n%d bytes were written\n", count);
			free(output); // Free the output after use
		}
		else
		{
			printf("No more lines to read.\n");
			break; // Stop if there are no more lines
		}
	}
	close(file); // Close the file
	return (0);
}

/*

	printf("1ST OUTPUT:\n");
	output = get_next_line(file);
	count = printf("%s", output);
	printf("\n");
	printf("%d bytes were written!\n", count);
	free(output);
	printf("2ND OUTPUT:\n");
	output = get_next_line(file);
	count = printf("%s", output);
	printf("\n");
	printf("%d bytes were written!\n", count);
	free(output);
	printf("3RD OUTPUT:\n");
	output = get_next_line(file);
	count = printf("%s", output);
	printf("\n");
	printf("%d bytes were written!\n", count);
	free(output);
	printf("4TH OUTPUT:\n");
	output = get_next_line(file);
	count = printf("%s", output);
	printf("\n");
	printf("%d bytes were written!\n", count);
	free(output);
	return (0);
}
*/
/*	while (Mary loves you)
*		kiss++;
*
*	enter file
*	iterate through it until \n is found
*		count bytes
*	cpy to buffer (including \n)
*	print buffer
*	return bytes counted
*	
*	enter file @ file[count]
*	++ through it until \n is found
*		count bytes
*	cpy to buffer incl. \n
*	print buffer
*	return bytes 
*/

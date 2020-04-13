#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char	*l_buffer;
	int			result;

	result = 0;
	if (l_buffer[0])
		l_buffer = (char*)calloc((BUFFER_SIZE +1), sizeof(char));
	if (BUFFER_SIZE < 1 && fd < 3 && !l_buffer)
		return(-1);
	while (!check_line(*line))
	{
		result = read(fd, l_buffer, BUFFER_SIZE);
		if (result > 0)
			*line = ft_strjoin(*line, l_buffer);
		else if (result == -1)
			return (-1);
	}
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	ptr = (char*)calloc(i + j + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	return (ptr);
}

int		check_line(char *ptr)
{
	int newline;
	int i;

	newline = 0;
	i = 0;
	while(ptr[i])
	{
		if(ptr[i] == '\n')
			newline = 1;
		i++;
	}
	return (newline);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t		i;

	ptr = (char*)malloc(count * size);
	i = 0;
	if (ptr)
	{
		while (i < count)
		{
			ptr[i] = '\0';
			i++;
		}
	}
	return (ptr);
}

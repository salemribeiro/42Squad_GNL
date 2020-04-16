#include "get_next_line.h"

/* Função principal para leitura de linha                                     */

int		get_next_line(int fd, char **line)
{
	static char	*s_line;
	char		*l_buffer;
	int			result;

	free(*line);
	*line = NULL;
	l_buffer = (char*)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	result = 0;
	if (!s_line)
		s_line = (char*)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (BUFFER_SIZE < 1 && fd < 3 && !s_line)
		return(-1);
	while (!check_line(s_line))
	{
		result = read(fd, l_buffer, BUFFER_SIZE);
		if (result > 0 &&  result <= BUFFER_SIZE)
			s_line = ft_strjoin(s_line, l_buffer);
		else
		{
			*line = s_line;
			return (-1);
		}
	}
	s_line = cleanline(line, s_line);
	free(l_buffer);
	return (result);
}



/* Função responsável por unir as duas strings                                */

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
	ptr = (char*)ft_calloc(i + j + 1, sizeof(char));
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

/* Função verifica se já temos uma linha completa                             */

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

/* Função responsável por alocar memória                                      */
/* foi modificada para retornar um ponteiro de char e bzero foi incluido no   */
/* código, evitando a implementação de mais uma função no arquivo             */

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

size_t		ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

size_t		ft_strlen(const char *source)
{
	int i;

	i = 0;
	while (source[i] != '\0')
		i++;
	return (i);
}

#include "get_next_line.h"

char	*cleanline(char **line, char *s_line)
{
	char	*l_temp;
	int		pos;
	pos = newline(s_line);
	if (pos >= 0)
	{
		s_line[pos] = '\0';
		*line = (char*)calloc(ft_strlen(s_line) + 1, sizeof(char));
		l_temp = (char*)calloc(ft_strlen(&s_line[pos + 1]) + 1, sizeof(char));
		ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
		ft_strlcpy(l_temp, &s_line[pos + 1], ft_strlen(&s_line[pos + 1]) + 1);
		free(s_line);
		return (l_temp);
	}
	free(*line);
	*line = (char*)calloc(ft_strlen(s_line + 1), sizeof(char));
	ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
	free(s_line);
	return (NULL);
}

int		newline(char *s_line)
{
	int i;
	int pos;
	i = 0;
	pos = -1;
	while (s_line[i])
	{
		if (s_line[i] == '\n' && pos == -1)
		{
			 pos = i;
			 return(pos);
		}
		i++;
	}
	return (pos);
}

/* Função responsável por contar caracteres na string.                        */
size_t		ft_strlen(const char *source)
{
	int i;

	i = 0;
	while (source[i] != '\0')
		i++;
	return (i);
}


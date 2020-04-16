#include "get_next_line.h"

char	*cleanline(char **line, char *s_line)
{
	char	*l_temp;
	int		i;
	int		j;
	
	i = 0;
	j = -1;
	free(*line);
	while (s_line[i])
	{
		if (s_line[i] == '\n' && j == -1)
			j = i;
		i++;
	}
	if (j >= 0)
	{
		s_line[j] = '\0';
		*line = (char*)calloc(ft_strlen(s_line) + 1, sizeof(char));
		l_temp = (char*)calloc(ft_strlen(&s_line[j + 1]) + 1, sizeof(char));
		ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
		ft_strlcpy(l_temp, &s_line[j + 1], ft_strlen(&s_line[j + 1]) + 1);
		free(s_line);
		return (l_temp);
	}
	*line = (char*)calloc(ft_strlen(s_line + 1), sizeof(char));
	ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
	free(s_line);
	return (NULL);
}

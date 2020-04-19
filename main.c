#include "get_next_line.h"

int main()
{
	static int	fd;
	int			ret;
	static char	*line;

	fd = open("./teste", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		if (*line)
		{
			free(line);
			line = NULL;
		}
	}
	if (*line)
	{
		free(line);
		line = NULL;
	}
	return (0);
}

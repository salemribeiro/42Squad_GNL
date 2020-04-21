#include "get_next_line.h"
#include <stdio.h>
int main()
{
	int			fd;
	int			ret;
	char		*line;

	fd = open("./1.txt", O_RDONLY);
	while((ret = get_next_line(fd, &line)))
	{
		if (*line)
		{
			printf("%s\n", line);
			free(line);
			line = NULL;
		}
	}
	if (ret >= 0)
	{
		if (*line)
		{
			printf("%s\n", line);
			free (line);
		}
	}
	return (0);
}

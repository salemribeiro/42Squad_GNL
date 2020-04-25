#include "get_next_line.h"
#include <stdio.h>
int main()
{
	int			fd;
	int			ret;
	char		*line;

	fd = open("./empty_file", O_RDONLY);
	while((ret = get_next_line(fd, &line)))
	{
			printf("%s\n", line);
			free(line);
	}
	return (0);
}

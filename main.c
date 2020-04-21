#include "get_next_line.h"
#include <stdio.h>
int main()
{
	int			fd;
	int			ret;
	char		*line;

	fd = open("./test_file7", O_RDONLY);
	do{
		ret = get_next_line(fd, &line);
		if (ret)
		{
			printf("%s\n", line);
			if (*line)
			{
				free(line);
				line = NULL;
			}
		}
	}while (ret);
	free (line);
	line = NULL;
	return (0);
}

#include "get_next_line.h"

int main()
{
	static int	fd;
	static char	*line;

	line = (char*)calloc((BUFFER_SIZE +1), sizeof(char));
	fd = open("./teste", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
	get_next_line(fd, &line);
	printf("%s", line);
	return (0);
}

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//caio está duvidando de mim outra vez
char		*ft_strjoin(char *s1, char *s2);
int			get_next_line(int fd, char **line);
char		*ft_calloc(size_t count, size_t size);
int			check_line(char *ptr);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlen(const char *source);
char		*cleanline(char **line, char *s_line);
int			newline(char *s_line);

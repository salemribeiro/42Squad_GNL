#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char		*ft_strjoin(char*, char*);
int			get_next_line(int, char**);
char		*ft_calloc(size_t, size_t);
int			check_line(char*);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlen(const char *source);
char		*cleanline(char **line, char *l_temp);
int			newline(char *s_line);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:58:33 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char		*ft_strjoin(char *s1, char *s2);
int			get_next_line(int fd, char **line);
char		*ft_calloc(size_t count, size_t size);
int			check_line(char *ptr);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlen(const char *source);
char		*cleanline(char **line, char *s_line);
int			newline(char *s_line);
void		ft_bzero(char *souce);

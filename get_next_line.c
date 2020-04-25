#include "get_next_line.h"

/* FUNÇÃO PRINCIPAL.                                                          */
/* Responsável por executar a leitura das linhas de um arquivo, realizando    */
/*   isto atráves de um loop, carregando os dados em pates discretas cujo o   */
/*   tamanho é definido em tempo de compilação através da flag "BUFFER_SIZE". */
/*        (gcc -Wall -Wextra -Wextra -D BUFFER_SIZE=70 -g *.c)                */
/* As partes são unidas formando uma linha e sua completude é definida após a */
/*   obtenção do carácter '\n'.                                               */
/* O término função é feito após o encontro de um '\n', '\0', erro ou fim de  */
/*   arquivo "EOF".                                                           */
/* O objetivo principal do exercício é o entendimento do modificador "static" */
/*   utilizado na persistência de dados em memória, treino com a biblioteca   */
/*   de "IO" e o uso responsável de alocação de memória.                      */
/* Este projeto mostra a dificuldade em lidar com as funções Malloc e Free.   */
int		get_next_line(int fd, char **line)
{
	static char	*s_line;
	char		*l_buffer;
	int			result;

	l_buffer = (char*)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	result = 0;
	if (!s_line)
		s_line = (char*)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (BUFFER_SIZE < 1 || fd < 0 || (fd > 0 && fd < 3) || !s_line)
		return(-1);
	while (!check_line(s_line))
	{
		result = read(fd, l_buffer, BUFFER_SIZE);
		if (result > 0 && result <= BUFFER_SIZE)
			s_line = ft_strjoin(s_line, l_buffer);
		else if (result == 0)
		{
			free(s_line);
			free(l_buffer);
			s_line = NULL;
			l_buffer = NULL;
			return (0);
		}
		else
		{
			free(s_line);
			free(l_buffer);
			s_line = NULL;
			l_buffer = NULL;
			return (-1);
		}
	}
	s_line = cleanline(line, s_line);
	free(l_buffer);
	l_buffer = NULL;
	return (1);
}

/* Função responsável por unir as duas strings.                               */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = (char*)ft_calloc(i + j + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (ptr);
}

/* Função validar se existe uma linha completa, ele verifica se o \n já está  */
/*   contido na função e retorna um inteiro verdadeiro ou falso.              */
int		check_line(char *ptr)
{
	int newline;
	int i;

	newline = 0;
	i = 0;
	while(ptr[i])
	{
		if(ptr[i] == '\n')
			newline = 1;
		i++;
	}
	return (newline);
}

/* Função responsável por alocar memória, foi modificada para retornar um     */
/*   ponteiro de char e foi mesclada a função bzero, evitando assim  a        */
/*   implementação de mais uma função no arquivo.                             */
char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t		i;

	ptr = (char*)malloc(count * size);
	i = 0;
	if (ptr)
	{
		while (i < count)
		{
			ptr[i] = '\0';
			i++;
		}
	}
	return (ptr);
}
/* Função responsável por copiar os dados de uma string para outra.           */
size_t		ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

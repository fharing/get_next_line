/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:38:08 by fharing           #+#    #+#             */
/*   Updated: 2021/07/13 10:19:32 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_end(char **line, char **re)
{
	*line = ft_strdup(*re);
	if (*line[0] == 0)
	{
		free(*line);
		*line = NULL;
	}
	free (*re);
	*re = NULL;
}

static char	*ft_fill(int bytesred, char **re, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (bytesred < 0)
		return (NULL);
	while (re[0][i] != '\0' && re[0][i] != '\n')
		i++;
	if (re[0][i] == '\n')
	{
		*line = ft_substr(*re, 0, i + 1);
		tmp = ft_strdup(&re[0][i + 1]);
		free (*re);
		*re = tmp;
		return (*line);
	}
	else
		ft_end(line, re);
	return (*line);
}

static int	ft_read(int bytesred, int fd, char *buff, char **re)
{
	char	*tmp;

	while (bytesred > 0)
	{
		buff[bytesred] = '\0';
		if (*re == NULL)
			*re = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(*re, buff);
			free (*re);
			*re = tmp;
		}
		if (ft_isnewline(buff) == 1)
			return (bytesred);
		bytesred = read(fd, buff, BUFFER_SIZE);
	}
	return (bytesred);
}

char	*get_next_line(int fd)
{
	char		*buff;
	int			bytesred;
	static char	*re;
	int			i;
	char		*line;

	i = 0;
	if (fd < 0)
		return (NULL);
	bytesred = 0;
	if (re == NULL || ft_isnewline(re) == 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		i = 1;
		bytesred = read(fd, buff, BUFFER_SIZE);
	}
	if (bytesred > 0)
		bytesred = ft_read(bytesred, fd, buff, &re);
	if (i == 1)
		free (buff);
	if (bytesred == 0 && re == NULL)
		return (NULL);
	return (ft_fill(bytesred, &re, &line));
}

int	main(void)
{
	char	*s = NULL;
	int		e = 1;
	int		fd = open("normal",O_RDONLY);
	if (fd == -1)
		return (0);
	while ((s = get_next_line(fd)) != NULL)
	{
		printf("%d OUTPUT: %s",e++,s);
		free(s);
	}
	if (close(fd) == -1)
		return (0);
}

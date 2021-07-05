/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:38:08 by fharing           #+#    #+#             */
/*   Updated: 2021/07/05 11:32:31 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_resetline(char **line)
{
	*line = ft_calloc(1, 1);
	return (0);
}

static char	*ft_strdup(char *tmp)
{
	char	*re;
	size_t	i;

	i = 0;
	re = (char *)malloc(ft_strlen(tmp) + 1);
	if (re == NULL)
		return (NULL);
	while (i < ft_strlen((tmp)))
	{
		re[i] = tmp[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}

static int	ft_fill(int bytesred, char **re, char **line)
{
	int		i;
	char	*tmp;

	if (bytesred < 0)
		return (-1);
	i = 0;
	while (re[0][i] != '\0' && re[0][i] != '\n')
		i++;
	if (re[0][i] == '\n')
	{
		*line = ft_substr(*re, 0, i);
		tmp = ft_strdup(&re[0][i + 1]);
		free (*re);
		*re = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(*re);
		free (*re);
		*re = NULL;
	}
	return (0);
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
			break ;
		bytesred = read(fd, buff, BUFFER_SIZE);
	}
	return (bytesred);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			bytesred;
	static char	*re;

	if (fd < 0 || line == NULL)
		return (-1);
	bytesred = read(fd, buff, BUFFER_SIZE);
	if (bytesred > 0)
		bytesred = ft_read(bytesred, fd, buff, &re);
	if (bytesred == 0 && re == NULL)
		return (ft_resetline(line));
	return (ft_fill(bytesred, &re, line));
}

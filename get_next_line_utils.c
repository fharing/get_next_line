/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:41:20 by fharing           #+#    #+#             */
/*   Updated: 2021/07/12 18:02:36 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *tmp)
{
	char	*re;
	size_t	i;

	i = 0;
	re = (char *)malloc(ft_strlen(tmp) + 1);
	if (re == NULL)
		return (NULL);
	while (tmp[i] != '\0')
	{
		re[i] = tmp[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*re;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	re = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (re == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		re[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
		re[i++] = s2[x++];
	re[i] = '\0';
	return (re);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*re;
	size_t	i;
	size_t	x;

	i = start;
	x = 0;
	if (s == NULL)
		return (NULL);
	re = (char *)malloc(len + 1);
	if (re == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		re[0] = 0;
		return (re);
	}
	while (s[i] != '\0' && x < len)
	{
		re[x] = s[i];
		x++;
		i++;
	}
	re[x] = '\0';
	return (re);
}

int	ft_isnewline(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

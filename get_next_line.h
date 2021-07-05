#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_isnewline(char *s);
int		ft_save_tmp(char *buff, char *tmp);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, size_t start, size_t len);

#endif

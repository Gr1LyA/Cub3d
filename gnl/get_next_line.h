#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef	BUFFER_SIZE
#  define	BUFFER_SIZE 42
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
char	*ft_str_new(size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
#endif
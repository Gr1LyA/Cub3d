#include "get_next_line.h"

char	*ft_cheker(char **remainder, char **line)
{
	char	*pointr_str;
	char	*s;

	pointr_str = NULL;
	if (*remainder)
	{
		pointr_str = ft_strchr(*remainder, '\n');
		if (pointr_str)
		{
			*pointr_str = '\0';
			*line = ft_strdup(*remainder);
			s = *remainder;
			*remainder = ft_strdup(++pointr_str);
			free(s);
		}
		else
		{
			*line = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	}
	else
		*line = ft_str_new(0);
	return (pointr_str);
}

int	ft_free_error(char **buf, int flag)
{
	free(*buf);
	return (flag);
}

int	ft_free_line(char **line, char *buf)
{
	char	*s;

	s = *line;
	*line = ft_strjoin(*line, buf);
	if (!*line)
		return (ft_free_error(&buf, -1));
	free(s);
	return (0);
}

int	ft_rem_chek(char *pointer_str, char *buf, char **remainder)
{
	if (pointer_str)
	{
		*pointer_str = '\0';
		*remainder = ft_strdup(++pointer_str);
		if (!*remainder)
			return (ft_free_error(&buf, -1));
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	size_t		b_read;
	char		*pointer_str;
	static char	*remainder;

	if (read(fd, 0, 0) < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	pointer_str = ft_cheker(&remainder, line);
	while (!pointer_str)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read <= 0)
			return (ft_free_error(&buf, b_read));
		buf[b_read] = '\0';
		pointer_str = ft_strchr(buf, '\n');
		if (ft_rem_chek(pointer_str, buf, &remainder) != 0)
			return (-1);
		if (ft_free_line(line, buf) != 0)
			return (-1);
	}
	return (ft_free_error(&buf, 1));
}

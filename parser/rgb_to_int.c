#include "../cub.h"

static void	sixteen(unsigned long num);

static char	*convert_to_hex(char **splt);

u_int32_t	convert_to_decimal(char **splt)
{
	char		*hex;
	size_t		len;
	size_t		i;
	char		*base;
	u_int32_t	color;

	hex = convert_to_hex(splt);

	// printf("hex = %s\n", hex);

	len = ft_strlen(hex);
	base = "0123456789abcdef";
	color = 0;
	i = -1;
	while (hex[++i])
		color += ((u_int32_t)(ft_findchr(base, hex[i])) * pow(16, --len));
	free(hex);
	// printf("color = %d\n", color);
	return (color);
}

static char	*convert_to_hex(char **splt)
{
	char	*hex;
	char	*tmp;
	char	*tmp1;
	int		i;
	int		fd;

	i = -1;
	while (++i < 3)
	{
		sixteen(ft_atoi(splt[i]));
		fd = open("./parser/hex.txt", O_RDONLY);
		if (!fd)
			exit (error_mess("error fd"));
		get_next_line(fd, &tmp);
		close(fd);
		if (!tmp)
			exit (error_mess("malloc"));
		if (i == 0)
			hex = tmp;
		else
		{
			tmp1 = hex;
			hex = ft_strjoin(hex, tmp);
			if (!hex)
				exit (error_mess("malloc"));
			free(tmp1);
			free(tmp);
		}
	}
	return (hex);
}

static void	sixteen_recursive(unsigned long num, int fd, char *base)
{
	if (num)
	{
		sixteen_recursive(num >> 4, fd, base);
		ft_putchar_fd(base[num % 16], fd);
	}
}

static void	sixteen(unsigned long num)
{
	char		*base;
	int			fd;

	fd = open("./parser/hex.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (!fd)
		exit (error_mess("error fd"));
	base = "0123456789abcdef";
	if (num < 16)
		ft_putstr_fd("0", fd);
	if (num == 0)
	{
		ft_putstr_fd("0", fd);
		close (fd);
		return ;
	}
	sixteen_recursive(num, fd, base);
	if (num == 0)
		ft_putstr_fd("0", fd);
	close (fd);
}
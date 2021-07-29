#include "../ft_printf.h"
#include <stdio.h>

static void	ft_putnbr_fd_long(unsigned int num, int fd)
{
	char			c;

	if (num >= 10)
		ft_putnbr_fd_long(num / 10, fd);
	c = num % 10 + '0';
	write(fd, &c, 1);
}

void	printf_u(obj* flags)
{
	unsigned int num;

	num = va_arg(flags->args, unsigned int);

	ft_putnbr_fd_long(num, 1);
	flags->count += 1;
	while (num >= 10)
	{
		num /= 10;
		flags->count += 1;
	}
}
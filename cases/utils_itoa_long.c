#include "../ft_printf.h"

static long long	count_len(long long n)
{
	if (n == 0)
		return (0);
	else
		return (1 + count_len(n / 10));
}

static long long	convert(long long n)
{
	long long	ret;

	if (n < 0)
		ret = (unsigned int)(n * -1);
	else
		ret = (unsigned int)n;
	return (ret);
}

static char	last_digit_to_char(long long n)
{
	if (n == 0)
		return ('0');
	else
		return ((char) '0' + n % 10);
}

char	*ft_long_itoa(long long n)
{
	char			*ret;
	int				x;
	long long		copy;
	int				len;

	len = 1 + count_len(n / 10);
	if (n < 0)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (ret);
	ret[len] = '\0';
	if (n < 1 && n > -1)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	copy = convert(n);
	x = len;
	while (copy)
	{
		ret[--x] = last_digit_to_char(copy);
		copy /= 10;
	}
	return (ret);
}

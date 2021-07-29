#include "../ft_printf.h"

char *ft_rev(char *str)
{
	int len;
	char *ret;
	int i;

	len = ft_strlen(str) - 1;
	ret = malloc(len + 2);
	i = 0;
	while (len >= 0)
	{
		ret[i] = str[len];
		i++;
		len--;
	}
	ret[i] = 0;
	return (ret);
}

char	*to_hex(unsigned long long num)
{
	char ret[1024];
	int i;

	i = 0;
	while (num > 0)
	{
		ret[i] = (num % 16) + 48;
		if (((num % 16) + 48) > 57)
			ret[i] = (num % 16) + 87;
		num = num / 16;
		i++;
	}
	ret[i] = 0;
	return (ft_rev(ret));
}
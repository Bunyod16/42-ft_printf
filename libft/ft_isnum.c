#include "libft.h"

int	ft_isnum(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

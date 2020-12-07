# include <stdio.h>
#include "libft.h"

int	main(void)
{
	int ret;
	int ret2;

	ret = ft_printf("%5s", "nark");
	printf (" output [%d]", ret);
	
	ret2 = printf("%5s", "nark");
	printf (" output [%d]", ret2);
	return (1);	
}

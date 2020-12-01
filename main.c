#include "libft.h"

int main(int argc, char **argv)
{

        (void)argc;
		int ret1;
		int ret2;
        ret1 = ft_printf("\n\n[MON PRINTF]\n%*s %s \n",10, argv[1], argv[2]);
      	printf("OUTPUT [%d]\n", ret1);
		ret2 = printf("\n\n[LE PRINTF]\n%*s %s \n", 10, argv[1], argv[2]);
      	printf("OUTPUT [%d]\n", ret2);
		return 1;
}

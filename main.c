#include "libft.h"

int main(int argc, char **argv)
{

        (void)argc;
		int ret1;
		int ret2;
		int a;
		char *z;

		a =	5;
        ft_printf("[MON PRINTF]\n");
		ret1 = ft_printf("%-05%");
      	printf("\nOUTPUT [%d]\n", ret1);
        printf("\n\n[PRINTF]\n");
		ret2 = printf("%-05%");
      	printf("\nOUTPUT [%d]\n", ret2);
		return 1;
}

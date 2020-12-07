#include "libft.h"

int main(int argc, char **argv)
{

        (void)argc;
		int ret1;
		int ret2;
		int a;
		int b;
		int c;
		int d;
		char *z;

		a =	5;
		b =	5;
		c =	5;
		d =	5;
        ft_printf("[MON PRINTF]\n");
		ret1 = ft_printf("%%");
      	printf("\nOUTPUT [%d]\n", ret1);
        printf("\n\n[PRINTF]\n");
		ret2 = printf("%p%p%60.35p%p", &a, &b, &c, &d);
      	printf("\nOUTPUT [%d]\n", ret2);
		return 1;
}

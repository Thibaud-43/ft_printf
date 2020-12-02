#include "libft.h"

int main(int argc, char **argv)
{

        (void)argc;
		int ret1;
		int ret2;

        ft_printf("[MON PRINTF]\n");
		ret1 = ft_printf("%s %s \n", argv[1], argv[2]);
      	printf("OUTPUT [%d]\n", ret1);

        printf("\n\n[PRINTF]\n");
		ret2 = printf("%s %s \n", argv[1], argv[2]);
      	printf("OUTPUT [%d]\n", ret2);
		return 1;
}

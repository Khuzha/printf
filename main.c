#include "printf.h"

// #define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)

int main()
{
        ft_printf("|%0-8.3X|\n", 8375);
	// printf("|%0-8.3X|\n", 8375);
	        int             a = -4;
        int             b = 0;
        char    c = 'a';
        int             d = 2147483647;
        int             e = -2147483648;
        // int             f = 42;
        // int             g = 25;
        // int             h = 4200;
        int             i = 8;
        int             j = -12;
        int             k = 123456789;
        int             l = 0;
        int             m = -12345678;
        // char    *n = "abcdefghijklmnop";
        // char    *o = "-a";
        // char    *p = "-12";
        // char    *q = "0";
        // char    *r = "%%";
        // char    *s = "-2147483648";
        // char    *t = "0x12345678";
        // char    *u = "-0";

	// ft_printf("|%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d|\n", 3, 3, 8, 3, 3, -12, 3, 3, 123456789, 3, 3, 0, 3, 3, -12345678, 3, 3, 97, 3, 3, -2147483648, 3, 3, 2147483647);
	// printf("|%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d|\n", 3, 3, 8, 3, 3, -12, 3, 3, 123456789, 3, 3, 0, 3, 3, -12345678, 3, 3, 97, 3, 3, -2147483648, 3, 3, 2147483647);

	// ft_printf("|%*.*d|\n", 3, 3, -12);
	// printf("|%*.*d|\n", 3, 3, -12);

	// ft_printf("|%u, %x, %X, %u|\n", l, l, l, m);
	//    printf("|%u, %x, %X, %u|\n", l, l, l, m);

	ft_printf("|%u, %x, %X, %u, %x, %X, %u, %x, %X, TUT %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X|\n", i, i, i, j, j, j, k, k, k, l, l, l,m, m, m, c, c, c, d, d, d, e, e, e);
	//    printf("|%u, %x, %X, %u, %x, %X, %u, %x, %X, TUT %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X|\n", i, i, i, j, j, j, k, k, k, l, l, l,m, m, m, c, c, c, d, d, d, e, e, e);
	while(1)
		i++;
}

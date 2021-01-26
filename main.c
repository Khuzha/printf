#include "printf.h"
// int		ft_printf(const char *format, ...);

int main()
{
	char *str = "|%0.5c|\n";
	int num = 0;
	char c = 'c';
	// ft_printf(str, num);
	printf(str, c);
}

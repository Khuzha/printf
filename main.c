#include "printf.h"
// int		ft_printf(const char *format, ...);

int main()
{
	char *str = "|%.0d|\n";
	int num = 0;
	ft_printf(str, num);
	printf(str, num);
}
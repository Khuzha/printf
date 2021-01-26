#include "printf.h"
// int		ft_printf(const char *format, ...);

int main()
{
	char *str = "|%.0c|\n";
	char c = 'c';
	ft_printf(str, c);
	printf(str, c);
}

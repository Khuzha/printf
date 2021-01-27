#include "printf.h"
// int		ft_printf(const char *format, ...);

int main()
{
	// char *format = "|%030s|\n";
	// char *str = "hello world";
	// // char c = 'c';
	// ft_printf(format, str);
	//    printf(format, str);

	char *format = "|%0-15d|\n";
	int value = -5000;
	ft_printf(format, value);
	printf(format, value);
}

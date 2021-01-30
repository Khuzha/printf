#include "printf.h"

int main()
{
	// ft_printf("|%7.7s%3.3s|\n", "hello", "world");
	// printf("|%7.7s%3.3s|\n", "hello", "world");

	ft_printf("|%5c|\n", '\0');
	printf("|%5c|\n", '\0');
}

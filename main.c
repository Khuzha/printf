#include "printf.h"

int main()
{
	ft_printf("|%-.09s|\n", "hi low");
	printf("|%-.15s|\n", "hi low");
}

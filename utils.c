#include "printf.h"


void	print_data(struct data *data)
{
	printf("===\ntype = %c, flag_minus = %d, flag_zero = %d, apply_acc = %d, width = %d, acc = %d\n===\n", data->type, data->flag_minus, data->flag_zero, data->apply_acc, data->width, data->acc);
}
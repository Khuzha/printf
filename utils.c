#include "printf.h"

void	handle_acc_str(struct data *data, char **str)
{
	char	*tmp;

	tmp = *str;
	*str = ft_substr(*str, 0, data->acc);
	free(tmp);
}

void	print_width(struct data *data, char *str, int len, int *count, int *w_in_end)
{
	int	counter;

	if (data->flag_minus && !(*w_in_end))
	{
		*w_in_end = 1;
		return ;
	}
	counter = 0;
	while (counter < data->width - len)
	{
		ft_putchar_fd(data->flag_zero ? '0' : ' ', 1);
		counter++;
	}
	// printf("counter = %d\n", counter);
}

// int		print_final(struct data *data, char *str, int len, int *count)
// {
// 	int w_in_end;

// 	w_in_end = 0;
// 	print_width(data, str, len, count, &w_in_end);
// 	if (data->apply_acc)
// 		handle_acc_str(data, &str);
// 	ft_putstr_fd(str, 1);
// 	return (*count);
// }
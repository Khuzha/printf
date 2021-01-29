#include "printf.h"

int		is_format_char(char c)
{
	char	*arr;

	arr = "%cspdiuxX*.0-";
	while (*arr)
	{
		if (*arr == c || ft_isdigit(c))
			return (1);
		arr++;
	}
	return (0);
}

int			parse_acc_or_w_simple(char *format, struct data *data, int is_acc)
{
	int	value;
	int i;

	i = 0;
	value = ft_atoi(format);
	if (is_acc && value >= 0)
	{
		data->acc = value;
		data->apply_acc = 1;
	}
	else
		data->width = value;
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

void		parse_acc_or_w_varg(struct data *data, int is_acc, va_list ap)
{
	int value;

	value = va_arg(ap, int);
	if (is_acc)
	{
		data->acc = value;
		data->apply_acc = 1;
	}
	else
	{
		data->width = value;
		if (value < 0)
		{
			data->flag_minus = 1;
			data->width *= -1;
		}
	}
	// print_data(data);
}

void		handle_if_type(char c, struct data *data)
{
	char	*types;

	types = "%cspdiuxX";
	if (data->flag_minus && data->flag_zero)
		data->flag_zero = 0;
	while (*types)
	{
		if (*types == c)
			data->type = c;
		types++;
	}
}

void		initialize_data(t_data *src)
{
	src->type = '0';
	src->apply_acc = 0;
	src->flag_minus = 0;
	src->flag_zero = 0;
	src->width = 0;
	src->acc = 0;
}

void			print_res(struct data *data, va_list ap, int *count)
{
	if (data->type == 'd' || data->type == 'i')
		return (print_d(data, va_arg(ap, int), count));
	if (data->type == 'c')
		return (print_c(data, va_arg(ap, int), count));
	if (data->type == '%')
		return (print_c(data, '%', count));
	if (data->type == 's')
		return (print_s(data, va_arg(ap, char *), count));
	if (data->type == 'p')
		return (print_p(data, va_arg(ap, unsigned long long), count));
	if (data->type == 'x' || data->type == 'X')
		return (print_x(data, va_arg(ap, unsigned int), count, (data->type == 'X')));
	// if (data->type == 'u')
	// 	return (print_u(data, va_arg(ap, unsigned int), count));
}

char	*parser(char *format, int *count, va_list ap)
{
	t_data *data;
	size_t	i;
	int		is_acc;
	char c;

	i = 0;
	is_acc = 0;
	data = (t_data *)malloc(sizeof(t_data));
	initialize_data(data);
	while (is_format_char(format[i]))
	{
		c = format[i];
		if ((format[i] == '0' && format[i + 1] == '-') || (format[i] == '-' && format[i + 1] == '0'))
		{
			data->flag_minus = 1;
			data->flag_zero = 0;
			i++;
		}
		format[i] == '0' && i == 0 ? data->flag_zero = 1 : 0;
		format[i] == '-' && i == 0 ? data->flag_minus = 1 : 0;
		if (ft_isdigit(format[i]) && (i != 0 || format[i] != 0))
			i += parse_acc_or_w_simple(&format[i], data, is_acc == 1 ? ((is_acc = 2)) : 0) - 1;
		if (format[i] == '*')
			parse_acc_or_w_varg(data, is_acc == 1 ? ((is_acc = 2)) : 0, ap);
		format[i] == '.' && !is_acc ? is_acc = 1 : 0;
		handle_if_type(format[i], data);
		i++;
	}
	print_res(data, ap, count);
	free(data);
	return (&format[i]);
}

int		ft_printf(const char *format, ...)
{
	int		count;
	char	*src;
	va_list	ap;

	count = 0;
	src = (char *)format;
	va_start(ap, format);
	while (*src)
	{
		if (*src == '%')
		{
			src = parser(src + 1, &count, ap);
			continue;
		}
		ft_putchar_fd(*src, 1);
		src++;
	}

	va_end(ap);
	return (count);
}

// int main()
// {
// 	char *str = "|%10c|\n";
// 	int num = -239810;
// 	char c = 'c';
// 	ft_printf(str, c);
// 	printf(str, c);
// }
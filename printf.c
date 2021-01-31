/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 05:37:40 by zskeeter          #+#    #+#             */
/*   Updated: 2021/01/31 10:32:49 by zskeeter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_res(t_data *data, va_list ap, int *count)
{
	int big_letters;

	big_letters = (data->type == 'X' ? 1 : 0);
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
		return (print_x(data, va_arg(ap, unsigned int), count, big_letters));
	if (data->type == 'u')
		return (print_u(data, va_arg(ap, unsigned int), count));
}

void	handle_flags(char *format, t_data *data, size_t *i)
{
	if ((*format == '0' && format[1] == '-') ||
		(*format == '-' && format[1] == '0'))
	{
		data->flag_minus = 1;
		data->flag_zero = 0;
		(*i)++;
	}
}

size_t	parser_loop(char *format, int *was_one, t_data *data, va_list ap)
{
	size_t	i;
	int		is_acc;

	i = 0;
	is_acc = 0;
	while (is_format_char(format[i]) && !(*was_one))
	{
		handle_flags(&format[i], data, &i);
		format[i] == '0' && i == 0 ? data->flag_zero = 1 : 0;
		format[i] == '-' && i == 0 ? data->flag_minus = 1 : 0;
		if (ft_isdigit(format[i]) && (i != 0 || format[i] != 0))
		{
			i += parse_acc_or_w_simple(&format[i], data,
				is_acc == 1 ? ((is_acc = 2)) : 0) - 1;
		}
		if (format[i] == '*')
			parse_acc_or_w_varg(data, is_acc == 1 ? ((is_acc = 2)) : 0, ap);
		format[i] == '.' && !is_acc ? is_acc = 1 : 0;
		format[i] == '.' && is_type(format[i + 1]) ? data->acc_no_value = 1 : 0;
		format[i] == '.' && is_type(format[i + 1]) ? data->apply_acc = 1 : 0;
		handle_if_type(format[i], data, was_one);
		i++;
	}
	return (i);
}

char	*parser(char *format, int *count, va_list ap)
{
	t_data	*data;
	size_t	i;
	int		was_one;

	was_one = 0;
	data = (t_data *)malloc(sizeof(t_data));
	initialize_data(data);
	i = parser_loop(format, &was_one, data, ap);
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
		ft_putchar_count(*src, &count);
		src++;
	}
	va_end(ap);
	return (count);
}

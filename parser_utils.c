/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 05:39:21 by zskeeter          #+#    #+#             */
/*   Updated: 2021/01/30 05:40:14 by zskeeter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	initialize_data(t_data *data)
{
	data->type = '0';
	data->apply_acc = 0;
	data->acc_no_value = 0;
	data->flag_minus = 0;
	data->flag_zero = 0;
	data->width = 0;
	data->acc = 0;
}

void	handle_if_type(char c, struct data *data, int *is_type)
{
	char	*types;

	types = "%cspdiuxX";
	if (data->flag_minus && data->flag_zero)
		data->flag_zero = 0;
	while (*types)
	{
		if (*types == c)
		{
			data->type = c;
			*is_type = 1;
			return ;
		}
		types++;
	}
}

int		parse_acc_or_w_simple(char *format, struct data *data, int is_acc)
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

void	parse_acc_or_w_varg(struct data *data, int is_acc, va_list ap)
{
	int value;

	value = va_arg(ap, int);
	if (is_acc)
	{
		if (value < 0)
			return ;
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:05:56 by zskeeter          #+#    #+#             */
/*   Updated: 2021/01/31 12:31:03 by zskeeter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	inite_str(t_data *data, char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		str[i] = data->flag_zero && !data->apply_acc ? '0' : ' ';
		i++;
	}
	str[i - 1] = '\0';
}

static void	handle_acc(t_data *data, char *str, int len)
{
	if (!data->acc)
		return ;
	if (data->flag_minus)
		ft_memset(str, '0', data->acc);
	if (!data->flag_minus)
		ft_memset(&str[len - data->acc], '0', data->acc);
}

static void	put_numbers(t_data *data, char *res, char *src, t_lengths *l)
{
	int i;
	int zerox_term;

	if (data->apply_acc && !data->acc && *src == '0' && !src[1])
		return ;
	if (l->f_len == l->len + 2 ||
		(data->flag_zero && !data->apply_acc) || data->flag_minus)
		zerox_term = 0;
	else
	{
		zerox_term = (l->f_len - (data->apply_acc && data->acc >= l->len ?
			data->acc : l->len) - 2);
	}
	if (data->flag_minus)
	{
		i = (data->apply_acc && data->acc >= l->len ?
			data->acc - l->len + 2 : 2);
	}
	else
		i = l->f_len - l->len;
	zerox_term = (zerox_term < 0 ? 0 : zerox_term);
	res[zerox_term] = '0';
	res[zerox_term + 1] = 'x';
	ft_memcpy(&res[i], src, l->len);
}

static void	make_str(t_data *data, char *src, t_lengths *lengths, int *count)
{
	char	*str;

	lengths->f_len = get_str_len_p(data, src, lengths->len);
	if (!(str = malloc(sizeof(char) * (lengths->f_len + 1))))
		return ;
	inite_str(data, str, lengths->f_len + 1);
	handle_acc(data, str, lengths->f_len);
	put_numbers(data, str, src, lengths);
	ft_putstr_count(str, count);
	count++;
	free(str);
}

void		print_p(t_data *data, unsigned long long value, int *count)
{
	char		*str;
	t_lengths	*lengths;

	if (!(lengths = malloc(sizeof(lengths))))
		return ;
	if (value)
		str = ft_itoa_for_p(value);
	else
		str = (data->acc_no_value ? "" : "0");
	if (data->flag_zero && data->width > data->acc && !data->apply_acc)
	{
		data->acc = data->width;
		data->apply_acc = 1;
		data->width = 0;
	}
	lengths->len = ft_strlen(str);
	make_str(data, str, lengths, count);
	free(lengths);
	value ? free(str) : 0;
}

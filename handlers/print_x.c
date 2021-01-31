/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:32:34 by zskeeter          #+#    #+#             */
/*   Updated: 2021/01/31 10:54:38 by zskeeter         ###   ########.fr       */
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

static void	handle_acc(t_data *data, char *str, char *src, int len)
{
	if (!data->acc)
		return ;
	if (data->flag_minus)
		ft_memset(str, '0', data->acc + (*src == '-' ? 1 : 0));
	if (!data->flag_minus)
		ft_memset(&str[len - data->acc], '0', data->acc);
}

static void	put_numbers(t_data *data, char *res, char *src, t_lengths *l)
{
	int i;
	int term;

	if (data->apply_acc && !data->acc && *src == '0' && !src[1])
		return ;
	term = (*src == '-' ? 1 : 0);
	if (data->flag_minus)
	{
		i = (data->apply_acc && data->acc >= l->len ?
			data->acc - l->len + term * 2 : term);
	}
	else
		i = l->f_len - l->len + term;
	if (*src == '-')
	{
		if (data->flag_minus)
			*res = '-';
		else
		{
			res[l->f_len - (data->apply_acc && data->acc >= l->len ?
				data->acc + 1 : l->len)] = '-';
		}
		src++;
	}
	ft_memcpy(&res[i], src, l->len);
}

static void	make_str(t_data *data, char *src, t_lengths *lengths, int *count)
{
	char	*str;

	lengths->f_len = get_str_len_x(data, src, lengths->len);
	if (!(str = malloc(sizeof(char) * (lengths->f_len + 1))))
		return ;
	inite_str(data, str, lengths->f_len + 1);
	handle_acc(data, str, src, lengths->f_len);
	put_numbers(data, str, src, lengths);
	ft_putstr_count(str, count);
	count++;
	free(str);
}

void		print_x(t_data *data, unsigned value, int *count, int big_letters)
{
	char		*str;
	int			len;
	t_lengths	*lengths;

	if (!(lengths = malloc(sizeof(lengths))))
		return ;
	if (data->flag_zero && data->width > data->acc && !data->apply_acc)
	{
		data->acc = data->width - (value < 0 ? 1 : 0);
		data->apply_acc = 1;
		data->width = 0;
	}
	str = ft_itoa_16(value, big_letters);
	lengths->len = ft_strlen(str);
	make_str(data, str, lengths, count);
	free(lengths);
	free(str);
}

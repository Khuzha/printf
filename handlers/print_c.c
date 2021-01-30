/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 08:32:58 by zskeeter          #+#    #+#             */
/*   Updated: 2021/01/30 08:33:05 by zskeeter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	get_str_len(t_data *data)
{
	if (data->width)
		return (data->width);
	return (1);
}

static void	inite_str(t_data *data, char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		str[i] = data->flag_zero ? '0' : ' ';
		i++;
	}
	str[i - 1] = '\0';
}

static void	make_str(t_data *data, char c, int *count)
{
	char	*str;
	int		full_len;

	full_len = get_str_len(data);
	if (!(str = malloc(sizeof(char) * (full_len + 1))))
		return ;
	inite_str(data, str, full_len + 1);
	if (c)
	{
		str[data->flag_minus ? 0 : full_len - 1] = c;
		ft_putstr_count(str, count);
	}
	else if (data->flag_minus && full_len > 1)
	{
		ft_putchar_count(0, count);
		ft_putstr_count(&str[1], count);
	}
	else if (!data->flag_minus && full_len > 1)
	{
		ft_putstr_count(&str[1], count);
		ft_putchar_count(0, count);
	}
	else
		ft_putchar_count(0, count);
	free(str);
}

void		print_c(t_data *data, char c, int *count)
{
	data->apply_acc = 0;
	make_str(data, c, count);
}

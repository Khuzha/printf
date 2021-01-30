/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:02:15 by zskeeter          #+#    #+#             */
/*   Updated: 2021/01/30 09:05:29 by zskeeter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	get_str_len_p(t_data *data, char *str, int len)
{
	if (data->apply_acc && !data->acc && *str == '0' && !str[1])
		return (data->width);
	if (data->apply_acc && (data->acc > data->width) && ((data->acc > len)))
		return (data->acc + 2);
	if (data->width > len)
	{
		return (data->width > len + 2 ?
			data->width : data->width + 2 - (data->width - len));
	}
	return (len + 2);
}

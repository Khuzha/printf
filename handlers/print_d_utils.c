/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 08:58:02 by zskeeter          #+#    #+#             */
/*   Updated: 2021/01/30 09:00:48 by zskeeter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	get_str_len_d(t_data *data, char *str, int len)
{
	if (data->apply_acc && !data->acc && *str == '0' && !str[1])
		return (data->width);
	if (data->apply_acc && (data->acc >= data->width) &&
		((data->acc > len && *str != '-') || (data->acc >= len && *str == '-')))
		return (data->acc + (*str == '-' ? 1 : 0));
	if (data->width > len)
		return (data->width);
	return (len);
}

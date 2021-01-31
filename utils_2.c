/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 11:15:57 by zskeeter          #+#    #+#             */
/*   Updated: 2021/01/31 11:17:21 by zskeeter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	reverse_str(char **res, char *str, int len)
{
	int i;

	if (!(*res = ft_strdup(str)))
		return ;
	i = 0;
	while (len)
	{
		(*res)[i] = str[len - 1];
		i++;
		len--;
	}
}

char	*ft_itoa_16(unsigned int value, int big_letters)
{
	int		i;
	int		mod;
	char	str[256];
	char	*res;

	i = 0;
	*str = '0';
	str[1] = '\0';
	while (value)
	{
		mod = value % 16;
		if (mod < 10)
			str[i] = '0' + mod;
		else
			str[i] = mod - 10 + (big_letters ? 'A' : 'a');
		value /= 16;
		i++;
	}
	str[*str == '0' && ft_strlen(str) == 1 ? 1 : i] = '\0';
	reverse_str(&res, str, i);
	return (res);
}

int		is_type(char c)
{
	char	*types;

	types = "%cspdiuxX";
	while (*types)
	{
		if (c == *types)
			return (1);
		types++;
	}
	return (0);
}

int		pos_or_zero(int num)
{
	if (num >= 0)
		return (num);
	return (0);
}

char	*ft_itoa_for_p(unsigned long long value)
{
	int		i;
	int		mod;
	char	str[256];
	char	*res;

	i = 0;
	while (value)
	{
		mod = value % 16;
		if (mod < 10)
			str[i] = '0' + mod;
		else
			str[i] = mod - 10 + 'a';
		value /= 16;
		i++;
	}
	str[i] = '\0';
	reverse_str(&res, str, i);
	return (res);
}

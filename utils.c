/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zskeeter <zskeeter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 11:15:12 by zskeeter          #+#    #+#             */
/*   Updated: 2021/01/31 11:16:18 by zskeeter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_max_int(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	ft_putstr_count(char *s, int *count)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, 1);
		s++;
		(*count)++;
	}
}

void	ft_putchar_count(char c, int *count)
{
	ft_putchar_fd(c, 1);
	(*count)++;
}

int		count_digits_u(long n)
{
	int counter;

	if (n == 0)
		return (1);
	counter = 0;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*res;
	int		len;
	int		pos;
	long	num;

	num = n;
	pos = num >= 0;
	len = count_digits(num) + (!pos ? 1 : 0);
	num *= pos ? 1 : -1;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	while (len >= 0)
	{
		res[len - 1] = num % 10 + 48;
		num /= 10;
		len--;
	}
	if (!pos)
		res[0] = '-';
	return (res);
}

#include "printf.h"

void	print_data(struct data *data)
{
	printf("===\ntype = %c, flag_minus = %d, flag_zero = %d, apply_acc = %d, width = %d, acc = %d\n===\n", data->type, data->flag_minus, data->flag_zero, data->apply_acc, data->width, data->acc);
}

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
	int i;
	int mod;
	char str[256];
	char *res;

	i = 0;
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
	str[i] = '\0';
	reverse_str(&res, str, i);
	return (res);
}

char	*ft_itoa_for_p(unsigned long long value, int big_letters)
{
	int i;
	int mod;
	char str[256];
	char *res;

	i = 0;
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
	str[i] = '\0';
	reverse_str(&res, str, i);
	return (res);
}

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

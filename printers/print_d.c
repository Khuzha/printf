#include "../printf.h"

	static int	get_str_len(struct data *data, char *str, int len)
	{
		if (data->apply_acc && !data->acc && *str == '0' && !str[1])
			return (data->width);
		if (data->apply_acc && (data->acc > data->width) && ((data->acc > len && *str != '-') || (data->acc >= len && *str == '-')))
			return (data->acc + (*str == '-' ? 1 : 0));
		if (data->width > len)
			return (data->width);
		return (len);
	}

static void	inite_str(struct data *data, char *str, int len)
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

static void	handle_acc(struct data *data, char *str, char *src, int len)
{
	if (!data->acc)
		return ;
	if (data->flag_minus)
		ft_memset(str, '0', data->acc + (*src == '-' ? 1 : 0));
	if (!data->flag_minus)
		ft_memset(&str[len - data->acc], '0', data->acc + (*src == '-' ? 1 : 0));
}

static void	put_numbers(struct data *data, char *res, char *src, int len, int full_len)
{
	int i;
	int term;

	if (data->apply_acc && !data->acc && *src == '0' && !src[1])
		return ;
	// print_data(data);
	term = (*src == '-' ? 1 : 0);
	if (data->flag_minus)
		i = (data->apply_acc && data->acc >= len ? data->acc - len + term * 2 : term);
	else
		i = full_len - len + term;
	if (*src == '-')
	{
		if (data->flag_minus)
			*res = '-';
		else
			res[full_len - (data->apply_acc && data->acc >= len ? data->acc + 1 : len)] = '-';
		src++;
		printf("str here = |%s|\n", res);
		// printf("minus ind = %d\n", full_len - (data->apply_acc && data->acc >= len ? data->acc + 1 : len));
	}
	// printf("i = %d\n", i);
	ft_memcpy(&res[i], src, len);
}

static void	make_str(struct data *data, char *src, int len, int *count)
{
	char	*str;
	int		full_len;

	full_len = get_str_len(data, src, len);
	printf("full_len = %d\n", full_len);
	if (!(str = malloc(sizeof(char) * (full_len + 1))))
		return ;
	inite_str(data, str, full_len + 1);
	handle_acc(data, str, src, full_len);
	put_numbers(data, str, src, len, full_len);
	ft_putstr_fd(str, 1);
	free(str);
}

int			print_d(struct data *data, int value, int *count)
{
	char	*str;
	int		len;

	if (data->flag_zero && data->width > data->acc && !data->apply_acc)
	{
		data->acc = data->width - (value < 0 ? 1 : 0);
		data->apply_acc = 1;
		data->width = 0;
	}
	str = ft_itoa(value);
	len = ft_strlen(str);
	make_str(data, str, len, count);
	free(str);
	return (count_digits(value) + value <= 0 ? 1 : 0);
}

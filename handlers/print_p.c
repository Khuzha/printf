#include "../printf.h"

static int	get_str_len(struct data *data, char *str, int len)
	{
		if (data->apply_acc && !data->acc && *str == '0' && !str[1])
			return (data->width);
		if (data->apply_acc && (data->acc > data->width) && ((data->acc > len)))
			return (data->acc + 2);
		if (data->width > len)
			return (data->width > len + 2 ? data->width : data->width + 2 - (data->width - len));
		return (len + 2);
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

static void	handle_acc(struct data *data, char *str, int len)
{
	if (!data->acc)
		return ;
	if (data->flag_minus)
		ft_memset(str, '0', data->acc);
	if (!data->flag_minus)
		ft_memset(&str[len - data->acc], '0', data->acc);
}

static void	put_numbers(struct data *data, char *res, char *src, int len, int full_len)
{
	int i;
	int zerox_term;

	if (data->apply_acc && !data->acc && *src == '0' && !src[1])
		return ;
	if (full_len == len + 2 || (data->flag_zero && !data->apply_acc) || data->flag_minus)
		zerox_term = 0;
	else
		zerox_term = (full_len - (data->apply_acc && data->acc >= len ? data->acc : len) - 2);
	if (data->flag_minus)
		i = (data->apply_acc && data->acc >= len ? data->acc - len + 2 : 2);
	else
		i = full_len - len;
	zerox_term = (zerox_term < 0 ? 0 : zerox_term);
	res[zerox_term] = '0';
	res[zerox_term + 1] = 'x'; 
	ft_memcpy(&res[i], src, len);
}

static void	make_str(struct data *data, char *src, int len, int *count)
{
	char	*str;
	int		full_len;

	full_len = get_str_len(data, src, len);
	if (!(str = malloc(sizeof(char) * (full_len + 1))))
		return ;
	inite_str(data, str, full_len + 1);
	handle_acc(data, str, full_len);
	put_numbers(data, str, src, len, full_len);
	ft_putstr_count(str, count);
	count++;
	free(str);
}

void			print_p(struct data *data, unsigned long long value, int *count)
{
	char	*str;
	int		len;

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
	len = ft_strlen(str);
	make_str(data, str, len, count);
	value ? free(str) : 0;
}

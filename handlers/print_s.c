#include "../printf.h"

static int	get_str_len(struct data *data, int len)
{
	if (data->width >= len || (data->apply_acc && data->width >= data->acc))
		return (data->width);
	if (data->apply_acc && data->acc < len)
		return (data->acc);
	return (len);
}

static void	inite_str(struct data *data, char *str, int len)
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

static void	put_str_to_line(struct data *data, char *res, char *src, int len, int full_len)
{
	int i;

	if (data->flag_minus)
		i = 0;
	else
		i = pos_or_zero(full_len - (data->apply_acc && data->acc < len ? data->acc : len));
	ft_memcpy(&res[i], src, (data->apply_acc ? data->acc : len));
}

static void	make_str(struct data *data, char *src, int len, int *count)
{
	char	*str;
	int		full_len;

	full_len = get_str_len(data, len);
	if (!(str = malloc(sizeof(char) * (full_len + 1))))
		return ;
	inite_str(data, str, full_len + 1);
	put_str_to_line(data, str, src, len, full_len);
	ft_putstr_count(str, count);
	count++;
	free(str);
}

void			print_s(struct data *data, char *str, int *count)
{
	int len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	make_str(data, str, len, count);
}
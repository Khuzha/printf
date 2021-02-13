#include "../printf.h"

static int	get_str_len(t_data *data, int len)
{
	if (data->width >= len || (data->apply_acc && data->width >= data->acc))
		return (data->width);
	if (data->apply_acc && data->acc < len)
		return (data->acc);
	return (len);
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

static void	put_str_to_line(t_data *data, char *res, char *src, t_lengths *l)
{
	int i;

	if (data->flag_minus)
		i = 0;
	else
	{
		i = pos_or_zero(l->f_len - (data->apply_acc && data->acc < l->len ?
			data->acc : l->len));
	}
	ft_memcpy(&res[i], src, (data->apply_acc ? data->acc : l->len));
}

static void	make_str(t_data *data, char *src, t_lengths *lengths, int *count)
{
	char	*str;

	lengths->f_len = get_str_len(data, lengths->len);
	if (!(str = malloc(sizeof(char) * (lengths->f_len + 1))))
		return ;
	inite_str(data, str, lengths->f_len + 1);
	put_str_to_line(data, str, src, lengths);
	ft_putstr_count(str, count);
	count++;
	free(str);
}

void		print_s(t_data *data, char *str, int *count)
{
	t_lengths	*lengths;

	if (!(lengths = malloc(sizeof(lengths))))
		return ;
	if (!str)
		str = "(null)";
	lengths->len = ft_strlen(str);
	make_str(data, str, lengths, count);
	free(lengths);
}

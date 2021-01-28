#include "../printf.h"

static int	get_str_len(struct data *data)
{
	if (data->width)
		return (data->width);
	return (1);
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

static void	make_str(struct data *data, char c, int *count)
{
	char	*str;
	int		full_len;

	full_len = get_str_len(data);
	if (!(str = malloc(sizeof(char) * (full_len + 1))))
		return ;
	inite_str(data, str, full_len + 1);
	str[data->flag_minus ? 0 : full_len - 1] = c;
	ft_putstr_count(str, count);
	count++;
	free(str);
}

void			print_c(struct data *data, char c, int *count)
{
	data->apply_acc = 0;
	make_str(data, c, count);
}
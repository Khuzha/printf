#include "../printf.h"

static int	get_str_len(struct data *data, int len)
{
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
		str[i] = data->flag_zero ? '0' : ' ';
		i++;
	}
	str[i - 1] = '\0';
	printf("str in inite = |%s|\n", str);
}

static void	put_str_to_line(struct data *data, char *res, char *src, int len, int full_len)
{
	int i;

	i = (!data->flag_minus ? full_len - len : 0);
	if (*src == '-')
	{
		// if ()
		res[full_len - (data->apply_acc && data->acc >= len ? data->acc + 1 : len)] = '-';
		src++;
	}
	ft_memcpy(&res[i], src, len);
}

static void	make_str(struct data *data, char *src, int len, int *count)
{
	char	*str;
	int		full_len;

	full_len = get_str_len(data, len);
	printf("full_len = %d\n", full_len);
	if (!(str = malloc(sizeof(char) * (full_len + 1))))
		return ;
	inite_str(data, str, full_len + 1);
	put_str_to_line(data, str, src, len, full_len);
	ft_putstr_fd(src, 1);
	count++;
	free(str);
}

int			print_s(struct data *data, char *str, int *count)
{
	int len;

	len = ft_strlen(str);
	data->apply_acc = 0;
	make_str(data, str, len, count);
	return (1);
}
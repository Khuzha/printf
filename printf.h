#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct	s_data
{
	char	type;
	int		flag_minus;
	int		flag_zero;
	int		apply_acc;
	int		acc_no_value;
	int		width;
	int		acc;
}				t_data;

typedef struct	s_lengths
{
	int	len;
	int	f_len;
}				t_lengths;

void			print_c(t_data *data, char c, int *count);
void			print_d(t_data *data, int value, int *count);
void			print_s(t_data *data, char *str, int *count);
void			print_u(t_data *data, unsigned int value, int *count);
void			print_p(t_data *data,
					unsigned long long value, int *count);
void			print_x(t_data *data,
					unsigned int value, int *count, int big_letters);
int				ft_printf(const char *format, ...);
int				count_digits(long n);
char			*ft_itoa_16(unsigned int value, int big_letters);
char			*ft_itoa_for_p(unsigned long long value);
int				ft_max_int(int a, int b);
void			print_data(t_data *data);
void			ft_putstr_count(char *s, int *count);
void			ft_putchar_count(char c, int *count);
char			*ft_itoa_u(unsigned int n);
int				is_type(char c);
int				pos_or_zero(int num);
int				is_format_char(char c);
void			initialize_data(t_data *data);
void			handle_if_type(char c, t_data *data, int *is_type);
int				parse_acc_or_w_simple(char *format,
					t_data *data, int is_acc);
void			parse_acc_or_w_varg(t_data *data, int is_acc, va_list ap);
int				get_str_len_d(t_data *data, char *str, int len);
int				get_str_len_p(t_data *data, char *str, int len);
int				get_str_len_u(t_data *data, char *str, int len);
int				get_str_len_x(t_data *data, char *str, int len);

#endif

#ifndef PRINTF_H
# define PRINTF_H

// DELETE:
#include <stdio.h>
// end of del
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct data
{
	char	type;
	int		flag_minus;
	int		flag_zero;
	int		apply_acc;
	int		acc_no_value;
	int		width;
	int		acc;
} t_data;

void		print_c(struct data *data, char c, int *count);
void		print_d(struct data *data, int value, int *count);
void		print_s(struct data *data, char *str, int *count);
void		print_u(struct data *data, unsigned int value, int *count);
void		print_p(struct data *data, unsigned long long value, int *count);
void		print_x(struct data *data, unsigned int value, int *count, int big_letters);
// int		print_final(struct data *data, char *str, int len, int *count);
int		ft_printf(const char *format, ...);
int		count_digits(long n);
char	*ft_itoa_16(unsigned int value, int big_letters);
char	*ft_itoa_for_p(unsigned long long value);
int		ft_max_int(int a, int b);

void	print_data(struct data *data);
void	ft_putstr_count(char *s, int *count);
void	ft_putchar_count(char c, int *count);
char	*ft_itoa_u(unsigned int n);
int		is_type(char c);

#endif
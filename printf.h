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
	int		width;
	int		acc;
} t_data;

int		print_c(struct data *data, char c, int *count);
int		print_d(struct data *data, int value, int *count);
int		print_s(struct data *data, char *str, int *count);
int		print_p(struct data *data, void *ptr, int *count);
int		print_u(struct data *data, unsigned int value, int *count);
int		print_x(struct data *data, unsigned int value, int *count, int big_letters);
// int		print_final(struct data *data, char *str, int len, int *count);
int		ft_printf(const char *format, ...);
int		count_digits(long n);
char	*ft_itoa_16(unsigned int value, int big_letters);

void	print_data(struct data *data);

#endif
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

int		print_d(struct data *data, int value, int *count);
int		print_c(struct data *data, char c, int *count);
// int		print_final(struct data *data, char *str, int len, int *count);
int		ft_printf(const char *format, ...);
int		count_digits(long n);

void	print_data(struct data *data);


#endif
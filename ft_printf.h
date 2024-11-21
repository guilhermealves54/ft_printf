#ifndef	FT_PRINTF_H

#define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int ft_printf(const char *format, ...);
int	print_c (int c);
int	print_s (char *str);
int	print_i (int d);
int	print_p (unsigned long long ptr);
int	print_u (unsigned int u);
int	print_x (unsigned int x);
int	print_X (unsigned int x);

#endif
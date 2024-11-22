/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:15:40 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/22 16:15:43 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formats(va_list args, const char var)
{
	int	count;

	count = 0;
	if (var == 'c')
		count += print_c (va_arg(args, int));
	else if (var == 's')
		count += print_s (va_arg(args, char *));
	else if (var == 'p')
		count += print_p (va_arg(args, unsigned long long));
	else if (var == 'd' || var == 'i')
		count += print_i (va_arg(args, int));
	else if (var == 'u')
		count += print_u (va_arg(args, unsigned int));
	else if (var == 'x')
		count += print_x (va_arg(args, unsigned int));
	else if (var == 'X')
		count += print_ux (va_arg(args, unsigned int));
	else if (var == '%')
		count += print_c ('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start (args, format);
	count = 0;
	if (!format || format[count] == '\0')
		return (0);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			count += formats (args, format[i + 1]);
			i++;
		}
		else
			count += print_c (format[i]);
		i++;
	}
	va_end (args);
	return (count);
}
/*
#include<stdio.h>
int	main(void)
{
	char	s1[] = "World";
	int		d;

	d = ft_printf("Character: %c, String: %s\n", 'A', "Hello");
	printf("%d\n", d);

	d = ft_printf("FT_PRINTF: Pointer: %p, Decimal: %d\n", NULL, 42);
	printf("%d\n", d);

	d = ft_printf("Unsigned: %u, Hex (lower): %x, Hex: %X\n", 255, 255, 255);
	printf("%d\n", d);

	d = ft_printf("FT_PRINTF: Percent sign: %%\n");
	printf("%d\n", d);

	d = printf("PRINTF: Character: %c, String: %s\n", 'A', "Hello");
	printf("%d\n", d);

	d = printf("PRINTF: Pointer: %p, Decimal: %d\n", NULL, 42);
	printf("%d\n", d);

	d = printf("Unsigned: %u, Hex (lower): %x, Hex: %X\n", 255, 255, 255);
	printf("%d\n", d);

	d = printf("PRINTF: Percent sign: %%\n");
	printf("%d\n", d);
}*/

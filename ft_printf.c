#include "ft_printf.h"
/*

1. escrever cada caracter da string format, ate encontrar um %.
2. quando encontra um % procura no caractere seguinte o tipo de var.
3. apos imprimir o tipo de var encontrado, retorna ao ponto 1.

*/
int	print_c (int c)
{
write (1, &c, 1);
return (1);
}

int	print_s (char *str)
{
if (!str)
{
	ft_putstr_fd ("(null)", 1);
	return (6);
}
ft_putstr_fd (str, 1);
return (ft_strlen(str));
}

int	print_i (int d)
{
	char	*tmp_str;
	int		len;

	tmp_str = ft_itoa (d);
	len = ft_strlen (tmp_str);
	ft_putstr_fd (tmp_str, 1);
	free (tmp_str);
	return (len);
}

int	print_p (unsigned long long ptr)
{
	char	hex[16];
	char	buffer[16];
	size_t	i;
	size_t	n;
	
	if (!ptr)
	{
		ft_putstr_fd ("(nil)", 1);
		return (5);
	}
	write (1, "0x", 2);
	i = 0;
	*hex = "0123456789abcdef";
	while (ptr > 0)
	{
		buffer[i++] = hex[ptr % 16];
		ptr /= 16;
	}
	n = i - 1;
	while (n >= 0)
		ft_putchar_fd (buffer[n], 1);
	return (i + 2);
}

int	print_u (unsigned int u)
{
	char	*tmp_str;
	int		len;

	tmp_str = ft_itoa ((int)u);		// alterei itoa para long
	len = ft_strlen (tmp_str);
	ft_putstr_fd (tmp_str, 1);
	free (tmp_str);
	return (len);
}

int	print_x (unsigned int x, const char var)
{

}


int	formats(va_list args, const char var)
{
	int	count;

	count = 0;
	if (var == 'c')
		count += print_c (va_arg(args, int));
	else if (var == 's')
		count += print_s (va_arg(args, char *));
	else if (var == 'i')
		count += print_i (va_arg(args, int));
	else if (var == 'p')
		count += print_p (va_arg(args, unsigned long long));	// criar func
	else if (var == 'u')
		count += print_u (va_arg(args, unsigned int));			// criar func
	else if (var == 'x')
		count += print_x (va_arg(args, unsigned int), var);		// criar func
	else if (var == '%')
	{
		ft_putchar_fd ('%', 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start (args, format);
	count = 0;
	if (!format || format[count] == '\0')
		return (NULL);
	while (format[count] != '\0')
	{
		if (format[count] == '%' && format[count + 1] != '\0')
		{
			count += formats (args, format[count + 1]);
		}
		else
			count += print_c (format[count]);
		count++;
	}
	va_end (args);
	return (count);
}

int	main(void)
{
	char	s1[] = "World";
	int		d;

	d = ft_printf ("Hello %s\n", s1);
	printf ("retorno ft_printf: %d\n", d);
	d = printf ("Hello %s\n", s1);
	printf ("retorno printf: %d\n", d);
}
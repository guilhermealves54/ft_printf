/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:15:50 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/22 16:15:52 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c)
{
	write (1, &c, 1);
	return (1);
}

int	print_s(char *str)
{
	if (!str)
	{
		ft_putstr_fd ("(null)", 1);
		return (6);
	}
	ft_putstr_fd (str, 1);
	return (ft_strlen(str));
}

int	print_i(int d)
{
	char	*tmp_str;
	int		len;

	tmp_str = ft_itoa (d);
	if (tmp_str == 0)
		return (0);
	len = ft_strlen (tmp_str);
	ft_putstr_fd (tmp_str, 1);
	free (tmp_str);
	return (len);
}

int	print_p(unsigned long long ptr)
{
	char	*hex;
	char	buffer[16];
	int		i;
	int		len;

	if (!ptr)
	{
		ft_putstr_fd ("(nil)", 1);
		return (5);
	}
	write (1, "0x", 2);
	i = 0;
	hex = "0123456789abcdef";
	while (ptr > 0)
	{
		buffer[i++] = hex[ptr % 16];
		ptr /= 16;
	}
	len = i;
	while (--i >= 0)
		ft_putchar_fd (buffer[i], 1);
	return (len + 2);
}

int	print_u(unsigned int u)
{
	char	*tmp_str;
	int		len;

	tmp_str = ft_itoa (u);
	if (tmp_str == 0)
		return (0);
	len = ft_strlen (tmp_str);
	ft_putstr_fd (tmp_str, 1);
	free (tmp_str);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:48:59 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/22 16:49:02 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned int x)
{
	char	buffer[16];
	char	*hex;
	int		i;
	int		len;

	if (x == 0)
	{
		ft_putchar_fd ('0', 1);
		return (1);
	}
	i = 0;
	hex = "0123456789abcdef";
	while (x > 0)
	{
		buffer[i] = hex[x % 16];
		x /= 16;
		i++;
	}
	len = i;
	while (--i >= 0)
		ft_putchar_fd (buffer[i], 1);
	return (len);
}

int	print_ux(unsigned int x)
{
	char	buffer[16];
	char	*hex;
	int		i;
	int		len;

	if (x == 0)
	{
		ft_putchar_fd ('0', 1);
		return (1);
	}
	i = 0;
	hex = "0123456789ABCDEF";
	while (x > 0)
	{
		buffer[i] = hex[x % 16];
		x /= 16;
		i++;
	}
	len = i;
	while (--i >= 0)
		ft_putchar_fd (buffer[i], 1);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:45:33 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:45:36 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*

converter int em string.
se for um numero positivo é uma conversão direta.
char = digito +48.

se for negativo, multiplicar por -1 e colocar '-' no inicio da string.

*/

static int	calc_size(long n)
{
	int	res;

	res = 0;
	if (n < 0)
		n *= -1;
	if (n <= 9)
		return (1);
	while (n > 9)
	{
		n = n / 10;
		res++;
	}
	return (res + 1);
}

static char	*fill(char *s, long n, int neg, size_t i)
{
	s[i] = '\0';
	while (i > 0)
	{
		i--;
		s[i] = (n % 10) + 48;
		n = n / 10;
	}
	if (neg == 1)
		s[i] = '-';
	return (s);
}

char	*ft_itoa(long n)
{
	size_t	i;
	int		neg;
	char	*s;

	neg = 0;
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	i = calc_size (n) + neg;
	s = malloc ((i + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	fill (s, n, neg, i);
	return (s);
}
/*
#include<stdio.h>
int main(void)
{
	int     n = 14*3;
	char    *s;

	s = ft_itoa(n);
	printf ("%s\n", s);
	free (s);
}*/
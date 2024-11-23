/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:47:13 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:47:15 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*

strchr procura um char(c) na string (s).
no final retorna um pointer para a pos do char enc.
se não encontrar nada retorna Null.

1. loop para procurar char.
2. se n encontrar, verificar se o char que procura é \0.
3. se n encontrar, retornar NULL.

*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	n;

	i = 0;
	n = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == n)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == n)
		return ((char *) &s[i]);
	return (NULL);
}
/*
#include<stdio.h>
int main(void)
{
	char  c[] = "Hello World!";
	char    *ptr = ft_strchr(c, 'W');
	printf ("%s", ptr);
}*/

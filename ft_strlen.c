/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:36:59 by gribeiro          #+#    #+#             */
/*   Updated: 2024/10/22 16:41:32 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*

Porque usar size_t?
size_t esta desenhado para aceitar valores maiores que unsigned em sistemas 
64bit
compatibilidade com outras funções como malloc que exigem valores size_t como 
entrada
facilita a leitura do codigo. ao ver size_t percebe-se que o valor ref ao 
tamanho de algo

porque usar const char?
para garantir que o valor daquela variavel é apenas de leitura e que nao deve 
ser alterado.

*/

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	size_t	i;
	char	*str = "Hello!";

	i = 0;
	i = ft_strlen(str);
	printf("%d\n", i);
}*/

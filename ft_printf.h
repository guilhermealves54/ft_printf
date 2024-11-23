/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:16:34 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/22 16:16:36 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		print_c(int c);
int		print_s(char *str);
int		print_i(int d);
int		print_p(unsigned long long ptr);
int		print_u(unsigned int u);
int		print_x(unsigned int x);
int		print_ux(unsigned int x);
char	*ft_itoa(long n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

#endif

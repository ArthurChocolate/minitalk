/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:37:38 by naqua             #+#    #+#             */
/*   Updated: 2021/10/28 14:38:50 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_u(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	len += ft_putchar((char)(nb % 10 + '0'));
	return (len);
}

int	ft_check_flags(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_flag_u(va_arg(args, int)));
	if (c == '%')
		return (ft_putchar(c));
	if (c == 'x')
		return (ft_puthexa(va_arg(args, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_puthexa(va_arg(args, int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_pointer(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	count;
	int		len;

	count = 0;
	len = 0;
	va_start(args, str);
	while (str[count])
	{
		if (str[count] == '%' && ft_strchr("cspdiuxX%", str[count + 1]))
		{
			len += ft_check_flags(str[++count], args);
			count++;
		}
		else
		{
			len += ft_putchar(str[count]);
			count++;
		}
	}
	va_end (args);
	return (len);
}

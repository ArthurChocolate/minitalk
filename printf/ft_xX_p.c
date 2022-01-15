/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:42:56 by naqua             #+#    #+#             */
/*   Updated: 2021/10/28 14:30:59 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(size_t nb, char *base)
{
	int		len;

	len = 0;
	if (nb >= 16)
		len += ft_hexa(nb / 16, base);
	len += ft_putchar((char)(base[nb % 16]));
	return (len);
}

int	ft_puthexa(unsigned int nb, char *base)
{
	return (ft_hexa(nb, base));
}

int	ft_pointer(void *ptr)
{
	int	len;

	len = 0;
	len += write (1, "0x", 2);
	len += ft_hexa((size_t)ptr, "0123456789abcdef");
	return (len);
}

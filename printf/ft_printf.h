/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:03:49 by naqua             #+#    #+#             */
/*   Updated: 2021/10/28 14:37:39 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/* main */

int		ft_printf(const char *str, ...);
int		ft_check_flags(char c, va_list args);
int		ft_flag_u(unsigned int nb);
int		ft_hexa(size_t nb, char *base);
int		ft_puthexa(unsigned int nb, char *base);
int		ft_pointer(void *ptr);

/* utils */

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

#endif

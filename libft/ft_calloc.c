/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:44:37 by naqua             #+#    #+#             */
/*   Updated: 2022/01/15 16:36:28 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	len;

	len = count * size;
	str = malloc(count * size);
	if (!str)
		return (0);
	while (len > 0)
	{
		str[len - 1] = 0;
		len--;
	}
	return (str);
}

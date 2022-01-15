/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:55:40 by naqua             #+#    #+#             */
/*   Updated: 2022/01/15 16:51:02 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_add_char(char *str, char c)
{
	size_t	i;
	char	*new_str;

	new_str = malloc(ft_strlen(str) + 2);
	if (!new_str)
		return (0);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}

static void	ft_convert(char *str)
{
	int				j;
	unsigned char	c;
	size_t			len;

	j = 1;
	c = 0;
	len = ft_strlen(str) - 1;
	while (len + 1 != 0)
	{
		c += j * (str[len] - '0');
		j *= 2;
		len--;
	}
	write(1, &c, 1);
}

static void	ft_verifi_signal(int signal)
{
	static char	*bits;
	static int	count;

	count++;
	if (!bits)
	{
		bits = ft_strdup("");
		count = 1;
	}
	if (signal == SIGUSR2)
		bits = ft_add_char(bits, '0');
	else
		bits = ft_add_char(bits, '1');
	if (count == 8)
	{
		ft_convert(bits);
		free(bits);
		bits = NULL;
	}
}

int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_verifi_signal);
		signal(SIGUSR2, ft_verifi_signal);
		pause();
	}
	return (0);
}

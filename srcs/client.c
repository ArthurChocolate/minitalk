/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:14:37 by naqua             #+#    #+#             */
/*   Updated: 2022/01/15 18:01:20 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
static void	ft_send_msg(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(80);
	}
}

static char	*ft_convert_to_bits(char *msg, int i, int j)
{
	char			*bitmsg;
	unsigned int	c;
	int				bytes;

	i = ft_strlen(msg);
	bitmsg = ft_calloc(i * 8 + 1, sizeof(char));
	if (!bitmsg)
		return (NULL);
	while (i != 0)
	{
		c = msg[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				bitmsg[ft_strlen(msg) * 8 - j - 1] = '1';
			else
				bitmsg[ft_strlen(msg) * 8 - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (bitmsg);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3)
	{
		ft_printf("Error\nWrong number of arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	msg = ft_convert_to_bits(argv[2], 0, 0);
	if (!msg)
	{
		ft_printf("Error\nConvert error\n");
		return (0);
	}
	ft_send_msg(pid, msg);
	free(msg);
}

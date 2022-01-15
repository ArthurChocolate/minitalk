/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:51:07 by naqua             #+#    #+#             */
/*   Updated: 2022/01/15 17:17:34 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return i;
}

static char	*ft_convert_to_bits(char *msg, int i, int j)
{
	char	*bitmsg;
	unsigned int		c;
	int		bytes;

	i = ft_strlen(msg);
	bitmsg = calloc(i * 8 + 1, sizeof(char));
	if (!bitmsg)
	{
		write(1, "xxx", 3);
		return (NULL);
	}
	while (i + 1 != 0)
	{
		c = msg[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			printf("%d\n", c);
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

static void	ft_convert(char *str)
{
	int				j;
	unsigned char	c;
	int len;

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

int	main(int argc, char **argv)
{
	int c = 226;
	int c1 = 157;
	int c2 = 164;

	//printf("%d\n", ft_strlen("❤"));
	printf("%s\n", ft_convert_to_bits("❤", 0, 0));
	//write(1, &c, 1);
	//write(1, &c1, 1);
	//write(1, &c2, 1);
	//ft_convert("11100010");
	//ft_convert("10011101");
	//ft_convert("10100100");
}

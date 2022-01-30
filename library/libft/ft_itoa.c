/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:29:25 by whan              #+#    #+#             */
/*   Updated: 2022/01/31 02:07:10 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(int n, char *str, size_t count)
{
	if (n < 0)
	{
		str[0] = '-';
		count++;
	}
	str[count] = '\0';
	if (n < 0)
	{
		while (--count)
		{
			str[count] = ((n % -10) * -1) + '0';
			n = n / 10;
		}
	}
	else
	{
		while (count--)
		{
			str[count] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		temp;
	int		count;
	int		sign;

	if (n != 0 && !n)
		return (NULL);
	sign = 0;
	if (n < 0)
		sign = 1;
	count = 0;
	if (n == 0)
		count = 1;
	temp = n;
	while (temp)
	{
		temp = temp / 10;
		count++;
	}
	str = (char *)malloc(sizeof(char) * (sign + count + 1));
	if (!str)
		return (NULL);
	str = ft_convert(n, str, count);
	return (str);
}
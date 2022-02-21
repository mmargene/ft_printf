/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_csdi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:36:36 by mmargene          #+#    #+#             */
/*   Updated: 2021/08/29 03:25:07 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
	{
		if (nb == INT32_MIN)
			nb += 1;
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_nstr(char *str, int n, int i)
{
	str[i - 1] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	i--;
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	int		n;
	int		i;
	char	*str;

	n = nb;
	i = ft_intlen(n);
	if (n == INT32_MIN)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_nstr(str, n, i);
	return (str);
}

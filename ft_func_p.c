/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:43:04 by mmargene          #+#    #+#             */
/*   Updated: 2021/08/29 03:02:04 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen_p(unsigned long long nb, int base)
{
	ssize_t	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	*ft_nstr_p(char *str, unsigned long long nb, int base, char *abc)
{
	int	i;

	i = ft_intlen_p(nb, base);
	str[i - 1] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	i--;
	while (nb > 0)
	{
		str[i] = abc[nb % base];
		nb /= base;
		i--;
	}
	return (str);
}

char	*ft_itoa_ptr(unsigned long long nb, int base, char *abc)
{
	int		i;
	char	*str;

	i = ft_intlen_p(nb, base);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_nstr_p(str, nb, base, abc);
	return (str);
}

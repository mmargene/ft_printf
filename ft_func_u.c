/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:43:31 by mmargene          #+#    #+#             */
/*   Updated: 2021/08/29 03:02:51 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen_u(unsigned int nb, int base)
{
	size_t	len;

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

char	*ft_nstr_u(char *str, unsigned long long nb, int base, char *abc)
{
	int	i;

	i = ft_intlen_u(nb, base);
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

char	*ft_itoa_u(unsigned int nb, int base, char *abc)
{
	int		i;
	char	*str;

	i = ft_intlen_u(nb, base);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_nstr_u(str, nb, base, abc);
	return (str);
}

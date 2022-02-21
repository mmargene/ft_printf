/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:43:46 by mmargene          #+#    #+#             */
/*   Updated: 2021/08/29 03:27:17 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_id(t_info *sinfo)
{
	int		id;
	char	*tmp;

	id = va_arg(sinfo->vl, int);
	tmp = ft_itoa(id);
	sinfo->bytes += write(1, tmp, ft_intlen(id));
	free(tmp);
	return (1);
}

int	ft_u(t_info *sinfo)
{
	int				u;
	char			*tmp;

	u = va_arg(sinfo->vl, unsigned int);
	tmp = ft_itoa_u(u, 10, DEC);
	if (tmp == NULL)
		sinfo->error = -1;
	sinfo->bytes += write(1, tmp, ft_intlen_u(u, 10));
	free(tmp);
	return (1);
}

int	ft_c(t_info *sinfo)
{
	int	c;

	c = va_arg(sinfo->vl, int);
	ft_putchar(c, sinfo);
	return (1);
}

int	ft_s(t_info *sinfo)
{
	char	*str;

	str = va_arg(sinfo->vl, char *);
	if (str == NULL)
		sinfo->bytes += write(1, "(null)", 6);
	else
		ft_putstr(str, sinfo);
	return (1);
}

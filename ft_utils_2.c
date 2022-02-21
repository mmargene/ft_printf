/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:43:51 by mmargene          #+#    #+#             */
/*   Updated: 2021/08/29 03:26:56 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ps(t_info *sinfo)
{
	sinfo->bytes += write(1, "%", 1);
	return (1);
}

int	ft_x(t_info *sinfo)
{
	char	*tmp;
	int		h;

	h = va_arg(sinfo->vl, int);
	tmp = ft_itoa_u(h, 16, DEC HEX_LR);
	if (tmp == NULL)
		sinfo->error = -1;
	sinfo->bytes += write(1, tmp, ft_intlen_u(h, 16));
	free(tmp);
	return (1);
}

int	ft_X(t_info *sinfo)
{
	char	*tmp;
	int		h;

	h = va_arg(sinfo->vl, int);
	tmp = ft_itoa_u(h, 16, DEC HEX_UR);
	if (tmp == NULL)
		sinfo->error = -1;
	sinfo->bytes += write(1, tmp, ft_intlen_u(h, 16));
	free(tmp);
	return (1);
}

int	ft_p(t_info *sinfo)
{
	char				*tmp;
	unsigned long long	h;

	sinfo->bytes += write(1, "0x", 2);
	h = va_arg(sinfo->vl, unsigned long long);
	tmp = ft_itoa_ptr(h, 16, DEC HEX_LR);
	if (tmp == NULL)
		sinfo->error = -1;
	sinfo->bytes += write(1, tmp, ft_intlen_p(h, 16));
	free(tmp);
	return (1);
}

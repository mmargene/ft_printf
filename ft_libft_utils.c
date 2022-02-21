/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:43:37 by mmargene          #+#    #+#             */
/*   Updated: 2021/08/29 02:34:18 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr_c(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr(char *s, t_info *sinfo)
{
	if (s)
		sinfo->bytes += write(1, s, ft_strlen(s));
}

void	ft_putchar(char c, t_info *sinfo)
{
	sinfo->bytes += write(1, &c, 1);
}

char	*ft_strdup(const char *s1)
{
	size_t	slen;
	size_t	i;
	char	*s2;

	slen = ft_strlen(s1);
	i = 0;
	s2 = malloc (sizeof(char) * (slen + 1));
	if (!s2)
		return (NULL);
	while (i <= slen)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

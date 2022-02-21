/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 00:01:31 by mmargene          #+#    #+#             */
/*   Updated: 2021/08/29 03:41:19 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_check(char flag, t_info *sinfo)
{
	if (flag == 'c')
		return (ft_c(sinfo));
	if (flag == 's')
		return (ft_s(sinfo));
	if (flag == 'd')
		return (ft_id(sinfo));
	if (flag == 'i')
		return (ft_id(sinfo));
	if (flag == 'u')
		return (ft_u(sinfo));
	if (flag == 'x')
		return (ft_x(sinfo));
	if (flag == 'X')
		return (ft_X(sinfo));
	if (flag == 'p')
		return (ft_p(sinfo));
	if (flag == '%')
		return (ft_ps(sinfo));
	return (1);
}

int	ft_parse(const char *format, t_info *sinfo)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (!ft_strchr_c(FLAG, format[i]))
				i++;
			ft_flag_check(format[i], sinfo);
			if (format[i] == 0)
				return (sinfo->bytes);
			i++;
		}
		else
			ft_putchar(format[i++], sinfo);
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	static t_info	*sinfo;
	int				error;

	error = -1;
	sinfo = (t_info *)malloc(sizeof(t_info));
	if (!sinfo)
		return (error);
	sinfo->bytes = 0;
	sinfo->error = 0;
	va_start (sinfo->vl, format);
	error = ft_parse(format, sinfo);
	if (sinfo->error != 0)
		return (sinfo->error);
	va_end(sinfo->vl);
	free(sinfo);
	return (sinfo->bytes);
}

// int main()
// {
// 	int i = 432423423423;
// 	char *s = "./gg!wp/";
// 	char c = '^';
// 	int u = -423423423;
// 	int x = 32424;
// 	int X = 1500;
// 	int ptr = 42342342345236523;
// 	// int ptr = -ULONG_MAX;
// 	// int ptr = ULONG_MAX;
// 	// int ptr = LONG_MAX;
// 	// int ptr = LONG_MIN;

// 	ft_printf("-------------------------------------\n");
// 	   printf("hello world /%%/ /%d/ /%s/ /%c/ /%u/ /%x/ 
// /%X/ /%p/ adb\n", i, s, c, u, x, X, ptr);
// 	ft_printf("-------------------------------------\n");
// 	ft_printf("hello world /%%/ /%d/ /%s/ /%c/ /%u/ /%x/ 
// /%X/ /%p/ adb\n", i, s, c, u, x, X, ptr);
// 	ft_printf("-------------------------------------\n");

// 	//    printf("\tbytes = %d\n",printf(" %p %p %p %p %p 
// %p %p", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, -ULONG_MAX, 0, 42));
// 	// printf("\tbytes = %d\n",ft_printf(" %p %p %p %p %p 
// %p %p", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, -ULONG_MAX, 0, 42));

// 	// sleep(1000);
// 	return(0);
// }

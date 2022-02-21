/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 00:01:22 by mmargene          #+#    #+#             */
/*   Updated: 2021/08/29 03:33:26 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include "ft_printf.h"

# define DEC	"0123456789"
# define HEX_LR	"abcdef"
# define HEX_UR	"ABCDEF"
# define FLAG	"cspduixX%"

// bytes = result
// error = any problems
// vl  	 = va_list
typedef struct s_info
{
	int			error;
	int			bytes;
	va_list		vl;
}						t_info;

//ft_libft_utils
size_t	ft_strlen(const char *s);
int		ft_strchr_c(const char *s, char c);
void	ft_putstr(char *s, t_info *sinfo);
void	ft_putchar(char c, t_info *sinfo);
char	*ft_strdup(const char *s1);

//ft_utils_1
int		ft_id(t_info *sinfo);
int		ft_u(t_info *sinfo);
int		ft_c(t_info *sinfo);
int		ft_s(t_info *sinfo);

//ft_utils_2
int		ft_ps(t_info *sinfo);
int		ft_x(t_info *sinfo);
int		ft_X(t_info *sinfo);
int		ft_p(t_info *sinfo);

//ft_func_csdi
int		ft_intlen(int nb);
char	*ft_nstr(char *str, int n, int i);
char	*ft_itoa(int nb);

//ft_func_p
int		ft_intlen_p(unsigned long long nb, int base);
char	*ft_nstr_p(char *str, unsigned long long nb, int base, char *abc);
char	*ft_itoa_ptr(unsigned long long nb, int base, char *abc);

//ft_func_u
int		ft_intlen_u(unsigned int nb, int base);
char	*ft_nstr_u(char *str, unsigned long long n, int base, char *abc);
char	*ft_itoa_u(unsigned int nb, int base, char *abc);

//ft_printf
int		ft_flag_check(char flag, t_info *sinfo);
int		ft_parse(const char *format, t_info *sinfo);
int		ft_printf(const char *str, ...);

#endif

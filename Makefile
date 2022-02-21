# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/28 19:44:00 by mmargene          #+#    #+#              #
#    Updated: 2021/08/29 03:34:32 by mmargene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_libft_utils.c ft_utils_1.c ft_utils_2.c \
				ft_func_csdi.c ft_func_p.c ft_func_u.c \
 				ft_printf.c 

# OBJS		=   ft_libft_utils.o ft_utils_1.o ft_utils_2.o \
# 				ft_func_csdi.o ft_func_p.o ft_func_u.o \
#  				ft_printf.o

OBJS		=	$(SRCS:%.c=%.o)
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

%.o: %.c 		ft_printf.h
			$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus

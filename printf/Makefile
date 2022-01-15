# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 12:46:08 by naqua             #+#    #+#              #
#    Updated: 2021/10/28 13:25:20 by naqua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCR	=	ft_printf.c \
			ft_utils.c \
			ft_xX_p.c

OBJS	= ${SRCR:.c=.o}
NAME	= libftprintf.a
CC		= clang
RM		= rm -f
INCLUDE	= ft_printf.h
FLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS} ${INCLUDE}
			ar rc ${NAME} ${OBJS}

all:		${NAME} ${INCLUDE}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

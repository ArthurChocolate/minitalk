# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 17:08:18 by naqua             #+#    #+#              #
#    Updated: 2021/12/31 17:13:24 by naqua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
NAME_S		=	server
NAME_C		=	client

SRCS_DIR	=	srcs
CLIENT_SRC	=	${SRCS_DIR}/client.c
SERV_SRC	=	${SRCS_DIR}/server.c

LIBFT		=	${LIBFT_PATH}/libft.a
LIBFT_PATH	=	./libft

PRINTF		=	${PRINTF_PATH}/libftprintf.a
PRINTF_PATH	=	./printf

CC			=	gcc
RM			=	rm -rf
FLAGS		=	-Wall -Werror -Wextra

${NAME}:
	${MAKE} -C ${PRINTF_PATH}
	${MAKE} -C ${LIBFT_PATH}
	${CC} ${FLAGS} ${CLIENT_SRC} ${LIBFT} ${PRINTF} -o client
	${CC} ${FLAGS} ${SERV_SRC} ${LIBFT} ${PRINTF} -o server

all: ${NAME}

clean:
	${MAKE} clean -C ${LIBFT_PATH}
	${MAKE} clean -C ${PRINTF_PATH}

fclean: clean
	${MAKE} fclean -C ${PRINTF_PATH}
	${MAKE} fclean -C ${LIBFT_PATH}
	${RM} ${NAME_S}
	${RM} ${NAME_C}

re: fclean all

.PHONY: all clean fclean re

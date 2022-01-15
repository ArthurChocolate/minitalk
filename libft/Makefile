# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 12:34:07 by naqua             #+#    #+#              #
#    Updated: 2021/12/17 17:07:44 by naqua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strnstr.c \
			  ft_atoi.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \

SRC_BONUS	= ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstdelone.c \
			  ft_lstadd_back.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c

OBJ			= ${SRC:.c=.o}
OBJ_BONUS	= ${SRC_BONUS:.c=.o}
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
NAME		= libft.a
RM			= rm -f
LIBC		= ar rc
LIBR		= ranlib
INCLUDES	= libft.h

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} ${INCLUDES}
	${LIBC} ${NAME} ${OBJ}
	${LIBR} ${NAME}

bonus: ${OBJ_BONUS} ${INCLUDES}
	${LIBC} ${NAME} ${OBJ_BONUS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: .c.o all clean fclean bonus re

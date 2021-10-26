# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmari <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 14:37:40 by wmari             #+#    #+#              #
#    Updated: 2021/10/26 14:43:55 by wmari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk

SRCS		=	client.c\
				server.c

OBJS		=	$(SRCS:.c=.o)

.c.o		:
				$(CC) -c $(CFLAGS) $^

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) -o client client.c
				$(CC) $(CFLAGS) -o server server.c


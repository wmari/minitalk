# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmari <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 14:37:40 by wmari             #+#    #+#              #
#    Updated: 2021/10/26 15:45:00 by wmari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk

SRCS		=	srcs/client.c\
				srcs/server.c

OBJS		=	$(SRCS:.c=.o)

.c.o		:
				@$(CC) $(CFLAGS) -o $@ -c $<

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) -o client srcs/client.o
				$(CC) $(CFLAGS) -o server srcs/server.o

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f server client

re			:	fclean all

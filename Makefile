# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 12:27:03 by hthomas           #+#    #+#              #
#    Updated: 2019/09/18 19:10:25 by mzblah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= srcs/bsq.c srcs/find_solution.c srcs/ft_putstr.c srcs/ft_strcat.c srcs/get_motif.c srcs/mallocs.c srcs/open_file.c srcs/parse_fill_tab.c srcs/print_solution.c
OBJS	= ${SRCS:.c=.o}
NAME	= bsq
CC		= gcc
CFLAGS = -Wall -Wextra -Werror
HELP = -g3 -fsanitize=address

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -Iincludes

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${HELP} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re

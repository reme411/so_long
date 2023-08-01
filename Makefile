# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rema <rema@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 15:58:51 by alalnaqb          #+#    #+#              #
#    Updated: 2023/08/01 14:21:03 by rema             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= solong.c \
			  imag.c \
			  keys.c solong_utilsz.c\
			  mapping.c  parsing.c\
			  solong_utils.c\
			  gnl/get_next_line.c \
			  gnl/get_next_line_utils.c \

	
OBJS = $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
LINKS			= -Lmlx -lmlx -framework OpenGL -framework AppKit
INCLUDE			= -Imlx

NAME			= so_long

all:			$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):		$(OBJS)
				make -C mlx
				make -C printf
				$(CC) $(INCLUDE) $(LINKS) $(OBJS) $(CFLAGS) ./printf/libftprintf.a  -o $(NAME)

clean:
				make -C mlx clean
				make -C printf clean
				$(RM) $(OBJS)

fclean:			clean
				make -C printf fclean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY: clean fclean re all 
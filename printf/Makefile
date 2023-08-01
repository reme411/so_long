# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rema <rema@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 10:14:10 by alalnaqb          #+#    #+#              #
#    Updated: 2023/07/16 18:08:52 by rema             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =  ft_printf.c ft_putchar.c printhex.c printnbr.c printptr.c printstr.c unsignbr.c \
	
OBJS = $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar -rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) ${BOBJS}

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY: clean fclean re all 
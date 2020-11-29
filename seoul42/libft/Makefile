# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 17:17:58 by japark            #+#    #+#              #
#    Updated: 2020/04/14 22:39:36 by japark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

cc = gcc

CFLAGS = -Wall -Werror -Wextra -Werror -I.

SRCS = *.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re

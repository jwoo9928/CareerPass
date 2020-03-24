# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 17:45:22 by japark            #+#    #+#              #
#    Updated: 2020/03/14 23:09:46 by japark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

cc = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = *.c

OBJS = $(subst .c,.o,$(SRCS))

libft_SRCS = ./libft/*.c

libft_OBJS = $(subst .c,.o,$(libft_SRCS))


all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS) $(libft_SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re
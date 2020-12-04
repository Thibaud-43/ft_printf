# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 17:04:20 by trouchon          #+#    #+#              #
#    Updated: 2020/12/04 14:14:12 by trouchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_itoa_unsigned_hexadecimal.c ft_pointers.c ft_itoa_unsigned.c ft_character.c ft_decimal_2.c ft_itoa.c ft_decimal.c ft_flags.c ft_isdigit.c ft_printf.c ft_string.c ft_strlen.c
OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS:.c=.o)
CC				= clang
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS) libftprintf.h.gch

fclean:			clean
					$(RM) $(NAME) 

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
					ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus

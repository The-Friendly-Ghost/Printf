# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cpost <cpost@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/07 14:00:19 by cpost         #+#    #+#                  #
#    Updated: 2022/01/29 15:43:16 by cpost         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_conversions.c \
		ft_printf.c \

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@ar -cr $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all


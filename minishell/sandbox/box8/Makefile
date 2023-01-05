# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 19:42:25 by seoyoo            #+#    #+#              #
#    Updated: 2023/01/05 14:01:28 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = cc
CFLAGS = -Wall -Wextra -Werror
DBFLAG = -g
RDLINE = -lreadline
CHECK_LEAKS = -g3 -fsanitize=address

all : $(NAME)
	@./$(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(CHECK_LEAKS) *.c
# $(CC) $(CFLAGS) *.c

clean :
	rm -rf $(NAME)*

re : clean all

.PONEY : all clean re
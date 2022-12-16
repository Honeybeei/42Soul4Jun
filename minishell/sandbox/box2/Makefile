# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 19:42:25 by seoyoo            #+#    #+#              #
#    Updated: 2022/12/16 17:07:15 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = cc
CFLAGS = -Wall -Wextra -Werror
DBFLAG = -g3
RDLINE = -lreadline

all : $(NAME)
	@./$(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(DBFLAG) $(RDLINE) *.c

clean :
	rm -rf $(NAME)*

re : clean all

.PONEY : all clean re
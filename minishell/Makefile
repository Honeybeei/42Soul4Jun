# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 20:16:40 by seoyoo            #+#    #+#              #
#    Updated: 2022/12/10 18:54:58 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color setting
Color_Off = \033[0m		# Text Reset
Black = \033[0;30m		# Black
Green = \033[0;31m		# Green
Green = \033[0;32m		# Green
Yellow = \033[0;33m		# Yellow
Blue = \033[0;34m		# Blue
Purple = \033[0;35m		# Purple
Cyan = \033[0;36m		# Cyan
White = \033[0;37m		# White

# **************************************************************************** #

# target
NAME = minishell

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
DBFLAG = -g3
EXTRAFLAGS =
# EXTRAFLAGS = -lreadline

# basic directories
SRC_DIR = ./src/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# include
INC_DIR = ./inc/
INC_FLAGS = -I $(INC_DIR)

COMPILE_FLAGS = $(CC) $(EXTRAFLAGS) $(CFLAGS) $(INC_FLAGS)
COMPILE_FLAGS_FOR_TEST = $(CC) $(DBFLAG) $(EXTRAFLAGS) $(INC_FLAGS)	# without -WWW
LINKING_FLAGS = $(CC) $(CFLAGS)

# **************************************************************************** #

SRC_FILE = _minishell_main.c test_functions.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

# **************************************************************************** #

all : $(NAME)

$(NAME) : $(OBJS)
	$(LINKING_FLAGS) -o $@ $^

$(OBJS) : $(SRCS)
	@mkdir -p $(OBJ_DIR)
	$(COMPILE_FLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

norm :
	@norminette ./inc ./src

.PONEY : all clean fclean re norm

# # **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 01:52:25 by seoyoo            #+#    #+#              #
#    Updated: 2023/01/08 19:40:18 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color setting
Color_Off = \033[0m		# Text Reset
Black = \033[0;30m		# Black
Red = \033[0;31m		# Red
Green = \033[0;32m		# Green
Yellow = \033[0;33m		# Yellow
Blue = \033[0;34m		# Blue
Purple = \033[0;35m		# Purple
Cyan = \033[0;36m		# Cyan
White = \033[0;37m		# White

# **************************************************************************** #

# target
NAME = my_lib.a

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
DBFLAG = -g3

# archive
AR = ar
ARFLAGS = -rcs

# include
INC_DIR = ./
INC = -I $(INC_DIR)

# basic directories
SRC_DIR = ./src/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# **************************************************************************** #

# LIBFT
LIBFT_DIR = libft/

# libft source
LIBFT_SRC_DIR = $(SRC_DIR)$(LIBFT_DIR)
LIBFT_SRC_FILE = \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

LIBFT_SRCS = $(addprefix $(LIBFT_SRC_DIR), $(LIBFT_SRC_FILE))

# libft object
LIBFT_OBJ_DIR = $(OBJ_DIR)$(LIBFT_DIR)
LIBFT_OBJ_FILE = $(LIBFT_SRC_FILE:.c=.o)
LIBFT_OBJS = $(addprefix $(LIBFT_OBJ_DIR), $(LIBFT_OBJ_FILE)) 
OBJS += $(LIBFT_OBJS)

# **************************************************************************** #

# improved_libft
IMPROVED_LIBFT_DIR = improved_libft/

# IMPROVED_LIBFT source
IMPROVED_LIBFT_SRC_DIR = $(SRC_DIR)$(IMPROVED_LIBFT_DIR)
IMPROVED_LIBFT_SRC_FILE = \
		my_calloc.c \
		my_malloc.c \
		my_strarrjoin.c \
		my_strcmp.c \
		my_strndup.c \
		my_strtransplant.c

IMPROVED_LIBFT_SRCS = $(addprefix $(IMPROVED_LIBFT_SRC_DIR), $(IMPROVED_LIBFT_SRC_FILE))

# improved_libft object
IMPROVED_LIBFT_OBJ_DIR = $(OBJ_DIR)$(IMPROVED_LIBFT_DIR)
IMPROVED_LIBFT_OBJ_FILE = $(IMPROVED_LIBFT_SRC_FILE:.c=.o)
IMPROVED_LIBFT_OBJS = $(addprefix $(IMPROVED_LIBFT_OBJ_DIR), $(IMPROVED_LIBFT_OBJ_FILE)) 
OBJS += $(IMPROVED_LIBFT_OBJS)

# **************************************************************************** #

# rules
all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	@printf "$(Green)\n[ my_lib compile finished!!] \n$(Color_Off)"

$(LIBFT_OBJ_DIR)%.o : $(LIBFT_SRC_DIR)%.c
	@mkdir -p $(LIBFT_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(IMPROVED_LIBFT_OBJ_DIR)%.o : $(IMPROVED_LIBFT_SRC_DIR)%.c
	@mkdir -p $(IMPROVED_LIBFT_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf ./obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PONEY: all bonus clean fclean re

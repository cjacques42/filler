# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacques <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 10:02:34 by cjacques          #+#    #+#              #
#    Updated: 2016/03/29 15:16:57 by cjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ_PATH = obj/
SRC_PATH = srcs/
SHELL = /bin/bash

SRC_NAME =		main.c			\
				list.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e "\033[32mCompile...\033[0m"
	@make -C libft/ all
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I includes -L libft -lft
	@echo -e "\033[32mDone\033[0m"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I includes -c $^ -o $@

clean:
	@echo -e "\033[32mClean\033[0m"
	@make -C libft/ clean
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHOONY: all clean fclean re norme

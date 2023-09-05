# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 10:43:51 by oroy              #+#    #+#              #
#    Updated: 2023/08/28 13:48:08 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME := libft.a
SRC_DIR := ./src
OBJ_DIR := ./obj
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

AR := ar rcs
CC := gcc
CFLAGS := -Wall -Werror -Wextra
HEADER := -I ./include
RM := rm -rf

# ********************************** RULES *********************************** #

all: $(NAME)
	@echo "-- Libft compiled --"

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir $@
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) $(HEADER) $< -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

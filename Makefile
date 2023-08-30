# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 18:36:54 by oroy              #+#    #+#              #
#    Updated: 2023/08/30 11:26:18 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME := so_long

GLFW := -L/Users/$(USER)/.brew/opt/glfw/lib -lglfw

LIBFT := ./lib/libft
LIBFT_AR := $(LIBFT)/libft.a

LIBMLX := ./lib/MLX42
LIBMLX_AR := $(LIBMLX)/build/libmlx42.a
LIBMLX_FLAGS := -ldl $(GLFW) -pthread -lm

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include

SRC_DIR := ./src
OBJ_DIR := ./obj
SRC := $(shell find $(SRC_DIR) -iname "*.c")
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC := gcc
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
RM := rm -rf

MK_C := $(MAKE) -C

# *********************************** RULES ********************************** #

all: $(LIBMLX_AR) $(LIBFT_AR) $(NAME)
	@echo "-- Project executable created --"

$(LIBMLX_AR):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && $(MK_C) $(LIBMLX)/build -j4

$(LIBFT_AR):
	@$(MK_C) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(OBJ) $(LIBMLX_AR) $(LIBMLX_FLAGS) $(LIBFT_AR) $(HEADERS) -o $(NAME)

$(OBJ_DIR):
	@mkdir $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(LIBMLX)/build
	@$(MK_C) $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MK_C) $(LIBFT) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft

bonus: 

# VALGRIND #

PARAM = test.ber

val: $(NAME)
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes -s \
	./$(NAME) $(PARAM)

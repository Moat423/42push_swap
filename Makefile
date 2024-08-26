# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:55:27 by lmeubrin          #+#    #+#              #
#    Updated: 2024/08/26 17:39:34 by lmeubrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
MAKEFLAGS += --warn-undefined-variables
.ONESHELL:

CC := cc
CFLAGS := -Werror -Wall -Wextra -g
SANITIZE_FLAGS := -fsanitize=address,undefined
NAME := push_swap
SANITIZE_NAME := $(NAME)_sanitize
LIBFT_DIR := libft
LIBFT_A := $(LIBFT_DIR)/libft.a
LIBFT := -lft
INCLUDES := -L$(LIBFT_DIR)

OBJ_DIR := obj

SRCS := main.c newlib.c ft_strtoimax.c ft_sort_int_tab.c operations.c sorting.c\
		operations2.c op_push.c helpers.c double_linked_list.c sorting_back.c \
		helpers_print.c targets.c moves.c dlist_helpers.c helpers_sorted.c \
		moves2.c helpers2.c positional_list.c op_push2.c ft_skip_whitespace.c

OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

HEADERS := push_swap.h

.PHONY: all, clean, fclean, re, submodules

all: submodules $(NAME)

run: all
	./$(NAME)

submodules:
	@git submodule status libft | grep -q '^-' && \
		echo "Initializing libft and its submodules..." && \
		git submodule update --init --recursive || true

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) -o $@

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -dRf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

sanitize: CFLAGS += $(SANITIZE_FLAGS)
sanitize: LDFLAGS += $(SANITIZE_FLAGS)

sanitize: CFLAGS += $(SANITIZE_FLAGS)
sanitize: re

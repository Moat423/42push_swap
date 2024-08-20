# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:55:27 by lmeubrin          #+#    #+#              #
#    Updated: 2024/08/20 17:03:56 by lmeubrin         ###   ########.fr        #
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
LIBFT := -lft
INCLUDES := -L$(LIBFT_DIR)

OBJ_DIR := obj

SRCS := main.c newlib.c ft_strtoimax.c ft_sort_int_tab.c operations.c sorting.c\
		operations2.c op_push.c helpers.c double_linked_list.c sorting_back.c \
		helpers_print.c targets.c moves.c dlist_helpers.c

OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

HEADERS := push_swap.h

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) -o $@

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJS): $(SRCS)

clean:
	rm -dRf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

sanitize: CFLAGS += $(SANITIZE_FLAGS)
sanitize: LDFLAGS += $(SANITIZE_FLAGS)
sanitize: $(SANITIZE_NAME)

run: all
	./push_swap

$(SANITIZE_NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $@

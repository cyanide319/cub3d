# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 12:36:25 by tbeaudoi          #+#    #+#              #
#    Updated: 2023/02/16 10:56:06 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

LIBMLX = MLX42/
MLX42 = MLX42/build/libmlx42.a

SRCS = src/cub3d.c \
		src/error.c \
		src/parsing_prime.c \
		src/utils_prime.c \
			 
OBJS = $(SRCS:.c=.o)

all: 	$(NAME)

$(MLX42):
	@brew install glfw
	@brew update

$(NAME): $(OBJS) $(MLX42)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX42) -I include -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/

build:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH)  clean
	# @rm -f $(LIBMLX)/build

fclean:	clean
	@$(RM) $(NAME) $(LIBFT) 

re:		fclean all
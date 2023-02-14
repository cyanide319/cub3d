# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 12:36:25 by tbeaudoi          #+#    #+#              #
#    Updated: 2023/02/14 13:28:47 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

D_MLX42 = MLX42/
MLX42 = MLX42/build/libmlx42.a

SRCS = src/cub3d.c \
			 
OBJS = $(SRCS:.c=.o)

all: 	$(NAME)

$(MLX42):
	@brew install glfw
	@brew update

$(NAME): $(OBJS) $(MLX42)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX42) -I include -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/

build: $(MLX42)
	cmake -B buildml ./MLX42/
	cmake --build build -j4 ./MLX42/

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH)  clean

fclean:	clean
	@$(RM) $(NAME) $(LIBFT) 

re:		fclean all
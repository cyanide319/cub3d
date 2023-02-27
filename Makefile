# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slord <slord@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 12:36:25 by tbeaudoi          #+#    #+#              #
#    Updated: 2023/02/27 18:35:44 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/

SRCS = src/cub3d.c \
		src/error.c \
		src/parsing_prime.c \
		src/parsing_secunde.c \
		src/parsing_tertie.c \
		src/parsing_quarte.c \
		src/utils_prime.c \
		src/raycasting.c \
		src/print.c \
		src/texture.c \
		src/move.c \
			 
OBJS = $(SRCS:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJS) 
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $@ $^ $(LIBFT) 

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH)  clean

fclean:	clean
	@$(RM) $(NAME) $(LIBFT) 

re:		fclean all
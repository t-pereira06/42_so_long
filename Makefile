# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:07:55 by tsodre-p          #+#    #+#              #
#    Updated: 2023/03/20 09:11:49 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft/libft.a
MLX = mlx/libmlx_Linux.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = srcs/so_long.c srcs/check_args.c srcs/check_map.c \
		srcs/map_errors.c srcs/map_errors_utils.c

OBJ = $(FILES:%.c=%.o)
FILES_O = srcs/so_long.o srcs/check_args.o srcs/check_map.o \
		srcs/map_errors.o srcs/map_errors_utils.o
all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLX):
	@$(MAKE) -C ./mlx

$(NAME): $(OBJ) $(LIBFT) $(MLX)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -o so_long

clean:
		@$(MAKE) clean -C ./libft
		@$(MAKE) clean -C ./mlx
		@$(RM) $(FILES_O)

fclean: clean
		@$(MAKE) fclean -C ./libft
		@$(RM) $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:07:55 by tsodre-p          #+#    #+#              #
#    Updated: 2023/04/06 11:53:38 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft/libft.a
MLX = mlx/libmlx_Linux.a

CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = srcs/so_long.c srcs/args.c srcs/map.c \
		srcs/map_path.c srcs/map_errors.c srcs/map_utils.c \
		srcs/free.c srcs/window.c srcs/events.c srcs/moves.c \
		srcs/moves_utils.c

OBJ = $(FILES:%.c=%.o)
FILES_O = srcs/so_long.o srcs/args.o srcs/map.o \
		srcs/map_path.o srcs/map_errors.o srcs/map_utils.o  \
		srcs/free.o srcs/window.o srcs/events.o srcs/moves.o \
		srcs/moves_utils.o
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

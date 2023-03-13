# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:26:29 by tsodre-p          #+#    #+#              #
#    Updated: 2022/11/07 16:02:46 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCS = $(shell find . -name '*.c')

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(FUNCS:%.c=%.o)
BONUS_OBJ = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)
clean:
		@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

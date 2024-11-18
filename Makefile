# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: braugust <braugust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 06:00:14 by braugust          #+#    #+#              #
#    Updated: 2024/11/18 08:29:25 by braugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c ft_parsing.c ft_parsing2.c free.c move.c map.c \
utils.c
CC =	cc -g3 -Wall -Werror -Wextra
DIRLIB = ./libft
DIRLIB2 = ./minilibx-linux

LIBFT = $(DIRLIB)/libft.a
MLXLIB = $(DIRLIB2)/libmlx.a

INCLUDE = -I/usr/include -Imlx -Iincludes
NAME =	so_long
OBJS =	$(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLXLIB)
	$(CC) $(OBJS) $(LIBFT) $(MLXLIB) -lXext -lX11 -o $(NAME)
	@echo "done !"

$(LIBFT) :
	@make -sC $(DIRLIB)

$(MLXLIB) :
	@make -sC $(DIRLIB2)

%.o : src/%.c
	@$(CC) -c $< -o $@ $(INCLUDE)
	#echo "compiling: $<"

clean :
	@make fclean -sC $(DIRLIB)
	@make clean -sC $(DIRLIB2)
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
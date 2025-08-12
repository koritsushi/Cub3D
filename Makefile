# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 14:17:00 by mliyuan           #+#    #+#              #
#    Updated: 2025/08/12 11:09:31 by mliyuan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	 srcs/error.c

HEADER		=	includes/cub3d.h

OBJS		=	$(SRCS:%.c=%.o)

%.o: %.c	$(HEADER)
			$(COMPILE) $(CCFLAGS) $(GGDB) -I. -c $< -o $(<:.c=.o)

LIBFTDIR	=	./libft/
LIBFT		=	$(LIBFTDIR)libft.a
MLXDIR		=	./minilibx-linux/
MLX			=	$(MLXDIR)libmlx_Linux.a
MLXCOMPILE	=	-L$(MLXDIR) -L$(LIBFTDIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
PROGRAM		=	cube3D
COMPILE		=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-ggdb3
FSAN		=	-fsanitize=address

$(NAME): $(LIBFT) $(MLX)
		@cp $(LIBFT) ./
		ar rcs $(LIBFT) $(MLX) 
		$(COMPILE) $(CCFLAGS) $(OBJS) $(MLXCOMPILE) srcs/main.c -o $(PROGRAM)

$(DEBUG): $(LIBFT) $(MLX)
		@cp $(LIBFT) ./
		ar rcs $(LIBFT) $(MLX) 
		$(COMPILE) $(CCFLAGS) $(OBJS) $(MLXCOMPILE) $(FSAN) srcs/main.c -o $(PROGRAM)

$(LIBFT):
		@make -C $(LIBFTDIR) all

$(MLX):
		@make -C $(MLXDIR) all

all:			$(NAME)

debug:			$(DEBUG)

clean:			
				@rm -rf $(OBJS)

fclean:			clean
				@rm -rf $(PROGRAM)

re:				fclean all

.PHONY	= all debug clean fclean re libft mlx
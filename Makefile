# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 14:17:00 by mliyuan           #+#    #+#              #
#    Updated: 2025/09/30 15:48:42 by mliyuan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	srcs/main.c				\
				srcs/error.c			\
				srcs/utils.c			\
				srcs/free.c				\
				srcs/parser.c			\
				srcs/parser_texture.c	\
				srcs/parser_colors.c	\
				srcs/parser_map.c		\
				srcs/parser_utils.c		\
				srcs/parser_utils2.c	\
				srcs/exec.c				\
				srcs/exec_updatestate.c \
				srcs/exec_dda.c			\
				srcs/exec_utils.c		\
				srcs/exec_utils2.c		\
				srcs/exec_utils3.c		\
				srcs/init_dummymap.c	\
				srcs/exec_render.c		\
				srcs/exec_texture.c		\
				srcs/exec_camera.c		\
				srcs/colour_utils.c		

HEADER		=	includes/cub3d.h

OBJS		=	$(SRCS:%.c=%.o)

%.o: %.c	$(HEADER)
			$(COMPILE) $(CCFLAGS) -ggdb3 -I. -c $< -o $(<:.c=.o)

LIBFTDIR	=	./libft/
LIBFT		=	$(LIBFTDIR)libft.a
MLXDIR		=	./minilibx-linux/
MLX			=	$(MLXDIR)libmlx_Linux.a
MLXCOMPILE	=	-L$(MLXDIR) -L$(LIBFTDIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME		=	cube3D
COMPILE		=	gcc -no-pie
CCFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-ggdb3
FSAN		=	-fsanitize=address

$(NAME): $(LIBFT) $(MLX) $(OBJS)
		$(COMPILE) $(CCFLAGS) $(DEBUG) $(OBJS) $(LIBFT) $(MLX) $(MLXCOMPILE) -o $(NAME)

$(DEBUG): $(LIBFT) $(MLX) $(OBJS)	
		$(COMPILE) $(CCFLAGS) $(DEBUG) $(FSAN) $(OBJS) $(LIBFT) $(MLX) $(MLXCOMPILE) -o $(NAME)
		
$(LIBFT):
		@make -C $(LIBFTDIR) all

$(MLX):
		@make -C $(MLXDIR) all

all:			$(NAME)

debug:			$(DEBUG)

clean:			
				@rm $(OBJS)
				@make clean -C $(LIBFTDIR)

fclean:			clean
				@make clean -C $(MLXDIR)
				@make fclean -C $(LIBFTDIR)
				@rm $(NAME)

re:				fclean all

.PHONY	= all debug clean fclean re libft mlx

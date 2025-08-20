# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 14:17:00 by mliyuan           #+#    #+#              #
#    Updated: 2025/08/20 13:51:43 by booi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	srcs/error.c	\
				srcs/parser.c	\
				srcs/exec.c		\
				srcs/update_state.c \
				srcs/dda.c

HEADER		=	includes/cub3d.h

OBJS		=	$(SRCS:%.c=%.o)

%.o: %.c	$(HEADER)
			$(COMPILE) $(CCFLAGS) $(GGDB) -I. -c $< -o $(<:.c=.o)

LIBFTDIR	=	./libft/
LIBFT		=	$(LIBFTDIR)libft.a
MLXDIR		=	./minilibx-linux/
MLX			=	$(MLXDIR)libmlx_Linux.a
MLXCOMPILE	=	-L$(MLXDIR) -L$(LIBFTDIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME		=	cube3D
COMPILE		=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-ggdb3
FSAN		=	-fsanitize=address

$(NAME): $(LIBFT) $(MLX) $(OBJS)
		$(COMPILE) $(CCFLAGS) $(OBJS) $(LIBFT) $(MLX) srcs/main.c $(MLXCOMPILE) -o $(NAME)

$(DEBUG): $(LIBFT) $(MLX) $(OBJS)	
		$(COMPILE) $(CCFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXCOMPILE) $(FSAN) srcs/main.c -o $(NAME)
		
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

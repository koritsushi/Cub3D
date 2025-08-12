# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 14:17:00 by mliyuan           #+#    #+#              #
#    Updated: 2025/08/12 13:37:36 by mliyuan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	

HEADER		=	includes/cub3d.h

OBJS		=	$(SRCS:%.c=%.o)
%.o: %.c	$(HEADER)
			$(COMPILE) $(CCFLAGS) $(GGDB) -I. -c $< -o $(<:.c=.o)

LIBFTDIR	=	./libft/
LIBFT		=	$(LIBFTDIR)libft.a
MLXDIR		=	./minilibx-linux/
MLX			=	$(MLXDIR)libmlx_Linux.a
MLXCOMPILE	=	-L$(MLXDIR) -L$(LIBFTDIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
PROGRAM		=	Cube3D
COMPILE		=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-ggdb3
FSAN		=	-fsanitize=address

$(NAME): $(LIBFT) $(MLX) $(OBJS)
		ar rcs $(PROGRAM).a $(OBJS) $(LIBFT) $(MLX)
		$(COMPILE) $(CCFLAGS) $(PROGRAM).a $(MLXCOMPILE) srcs/main.c -o $(PROGRAM)
		@rm $(OBJS) $(PROGRAM).a 

$(DEBUG): $(LIBFT) $(MLX) $(OBJS)
		ar rcs $(PROGRAM).a $(OBJS) $(LIBFT) $(MLX)		
		$(COMPILE) $(CCFLAGS) $(PROGRAM).a $(MLXCOMPILE) $(FSAN) srcs/main.c -o $(PROGRAM)
		@rm $(OBJS) $(PROGRAM).a 

$(LIBFT):
		@make -C $(LIBFTDIR) all

$(MLX):
		@make -C $(MLXDIR) all

all:			$(NAME)

debug:			$(DEBUG)

clean:			
				@make clean -C $(LIBFTDIR)
				@rm -rf $(OBJS)

fclean:			clean
				@make clean -C $(MLXDIR)
				@make fclean -C $(LIBFTDIR)
				@rm $(PROGRAM)

re:				fclean all

.PHONY	= all debug clean fclean re
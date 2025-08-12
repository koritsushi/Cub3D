# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 14:17:00 by mliyuan           #+#    #+#              #
#    Updated: 2025/08/12 11:01:33 by mliyuan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	 srcs/error.c

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
HEADER		= 

$(NAME): $(LIBFT) $(MLX) $(OBJS)
		@cp $(LIBFT) $(NAME)
		ar rcs $(PROGRAM) $(LIBFT) $(MLX) 
		$(COMPILE) $(CCFLAGS) $(OBJS) $(MLXCOMPILE) srcs/main.c -o $(PROGRAM)

$(DEBUG): $(OBJS)
		@cp $(LIBFT) $(NAME)
		ar rcs $(PROGRAM) $(LIBFT) $(MLX) 
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
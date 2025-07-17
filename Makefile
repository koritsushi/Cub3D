# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 14:17:00 by mliyuan           #+#    #+#              #
#    Updated: 2025/07/17 14:20:29 by mliyuan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

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
HEADER		=

$(NAME): $(OBJS)
		$(COMPILE) $(CCFLAGS) $(OBJS) srcs/main.c -o $(NAME)

$(DEBUG): $(OBJS)
		$(COMPILE) $(CCFLAGS) $(OBJS) $(FSAN) srcs/main.c -o $(NAME)

all:			$(NAME)

debug:			$(DEBUG)

clean:			
				@rm -rf $(OBJS)

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

.PHONY	= all debug clean fclean re
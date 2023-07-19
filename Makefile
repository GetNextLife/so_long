# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 16:28:13 by smitsobo          #+#    #+#              #
#    Updated: 2023/07/12 17:34:33 by smitsobo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS =-Werror -Wextra -Wall

MFLAGS = -lX11 -lXext -lm -lz

CC = cc -g

SOURCES = controls1.c \
			controls2.c \
			main.c \
			utils.c \
			utils2.c \
			ft_split.c \
			init_image.c \
			utils3.c \
			moves.c

OBJS = $(SOURCES:.c=.o)

LIBS =  minilibx-linux/libmlx.a \
		minilibx-linux/libmlx_Linux.a \

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(FLAGS) $(OBJS) $(LIBS) $(MFLAGS) -o $(NAME) -g
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 17:29:23 by hrazanam          #+#    #+#              #
#    Updated: 2021/10/17 12:10:07 by hrazanam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

LIBMLX	= ../minilibx/libmlx.a

SRCS	= fractol.c \
	  utils.c \
	  put_to_image.c \
	  mandelbrot.c \
	  julia.c \
	  ft_atof.c \
	  zoom.c \
	  zoom_central.c \
	  translate.c \
	  utils_atof.c \
	  close.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

LIBFLAG = -framework OpenGL -framework AppKit

RM	= rm -f

all: $(NAME) 

$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(OBJS) ../minilibx/libmlx.a -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBMLX):
	make -C ../minilibx

$(OBJS): 
	$(CC) -c $(FLAGS) $(SRCS)

all:		$(NAME)

clean:
		$(RM) ../minilibx/obj/*.o
		$(RM) $(OBJS) 

fclean:		clean
			$(RM) ../minilibx/libmlx.a
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

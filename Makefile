# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/19 10:32:42 by hsabouri          #+#    #+#              #
#    Updated: 2017/01/04 15:38:14 by hsabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBPATH = libft
LIBNAME = libft.a
LIB = $(LIBNAME:%=$(LIBPATH)/%)
CFLAGS = -Wall -Wextra -I$(INC)
CFLAGS += -O2 -march=native
#CFLAGS += -g -fsanitize=address
LDFLAGS = -L $(LIBPATH) -l$(LIBNAME:lib%.a=%) -lmlx -framework OpenGL\
			-framework AppKit
CC = gcc
SRC	= main.c g_pixel_put.c g_new_image.c g_refresh.c g_color.c m_fract.c \
	 error.c g_keyboard.c g_mouse.c g_move.c
INC = $(LIBPATH)/includes/
OBJ	= $(SRC:%.c=%.o)
OBJDIR = obj

all: $(NAME) $(LIB) 

$(LIB):
	$(MAKE) -C $(LIBPATH)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $@ $(LDFLAGS) $(OBJ) $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C $(LIBPATH)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBPATH)

re: fclean
	$(MAKE) all

norme:
	norminette $(SRC) $(INC) fractol.h

git:
	git add $(SRC) $(INC) Makefile
	git commit -m "$(M)"
	git push origin master

.PHONY: all clean fclean re norme

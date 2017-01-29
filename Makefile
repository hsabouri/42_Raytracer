# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/31 16:22:08 by ple-lez           #+#    #+#              #
#    Updated: 2017/01/29 18:40:24 by ple-lez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt
LFT = libft/libft.a
LIBS = $(LFT) -L./ -lmlx
HPATH = -I./
SRC = main.c \
	  mlx.c \
	  math.c \
	  init.c \
	  camera.c \
	  intersect.c \
	  raytrace.c \
	  vector_methods.c \
	  vector_operations.c \
	  quaternion_operations.c
CC = gcc -Wall -Werror -Wextra
C_MLX = $(MLX) -framework OpenGL -framework AppKit
AR = ar libft.a
RM = rm -rf
SRCDIR = $(addprefix ./sources/, $(SRC))
OBJDIR = obj
OBJ = $(addprefix ./$(OBJDIR)/, $(SRC:.c=.o))

$(NAME):
	@make -C libft
	@$(CC) -c $(SRCDIR)
	@mkdir -p $(OBJDIR) && mv $(SRC:.c=.o) ./$(OBJDIR)/
	@$(CC) -o $(NAME) $(OBJ) $(LIBS) $(C_MLX) $(HPATH)

all: $(NAME)

clean:
	@$(RM) $(OBJDIR)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

re: fclean
	@make re -C libft
	@make all
	@make clean

.PHONY: all clean fclean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/31 16:22:08 by ple-lez           #+#    #+#              #
#    Updated: 2017/02/15 14:33:51 by ple-lez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt
LDFLAGS = -L./
HFLAGS = -I./

LIBFT = libft/libft.a
HFLAGS += -I./libft/includes/
LDFALGS += -L./libft/

LIBVEC = libvec/libvect.a
HFLAGS += -I./libvec/includes/
LDFALGS += -L./libvec/

#Make the mlx lib working in 42 USA
ifeq ($(PLACE), USA)
	LIBMLX = libmlx_elcapitan/libmlx.a
	HFLAGS += -I./libmlx_elcapitan/
	LDFLAGS += $(LIBMLX) -framework OpenGL -framework AppKit
else
	#Make changes here
	LIBMLX = libmlx_elcapitan/libmlx.a
	HFLAGS += -I./libmlx_elcapitan/
	LDFLAGS += $(LIBMLX) -framework OpenGL -framework AppKit
endif

SRCDIR = sources
SRCS = main.c \
	  mlx.c \
	  init.c \
	  light.c \
	  camera.c \
	  normal.c \
	  quadra.c \
	  shadows.c \
	  raytrace.c \
	  intersect.c 
SRC = $(SRCS:%.c=$(SRCDIR)/%.c)

CC = gcc
CFLAGS = -Wall -Wextra
#CFLAGS += -Werror
#CFLAGS += -march=native -03
OBJ = $(SRC:$(SRCDIR)/%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C libvec/
	$(CC) -o $@ $(LDFLAGS) $(LIBVEC) $(OBJ) $(CFLAGS)

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(HFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean
	$(MAKE) all

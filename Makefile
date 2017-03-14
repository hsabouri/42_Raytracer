# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/31 16:22:08 by ple-lez           #+#    #+#              #
#    Updated: 2017/03/10 16:37:58 by qduperon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===========================================================#
#                    //   PROGRAM  \\                       #
#===========================================================#

NAME = RT

#===========================================================#
#                    //   VARIABLE  \\                      #
#===========================================================#

H_DIR = includes
C_DIR = ./sources
C_DIR += ./opencl
O_DIR = ./objects

LINKS = -I$(H_DIR)
LINKS += -Ilib/libobj/includes/
LINKS += -Ilib/libvec/includes/
LINKS += -Ilib/libft/
LINKS += -Ilib/libmlx_elcapitan
LINKS += -Ilib/libmalloc

C_FILES = $(shell find $(C_DIR) -type f -print | grep "\.c")
C_DIRS = $(shell find $(C_DIR) -type d -print)

O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

LIBFT = lib/libft/libft.a
LDFALGS += -L./lib/libft/

LIBVEC = lib/libvec/libvect.a
#HFLAGS += -I./libvec/includes/
LDFALGS += -L./lib/libvec/

LIBOBJ = lib/libobj/libobj.a
LDFALGS += -L./lib/libobj

LIBMALLOC = lib/libmalloc/libmalloc.a
LDFALGS += -L./lib/libmalloc

LIBMLX = lib/libmlx_elcapitan/libmlx.a
HFLAGS += -I./lib/libmlx_elcapitan/
LDFLAGS += $(LIBMLX) -framework OpenGL -framework AppKit -framework OpenCL

CC = gcc
CFLAGS = -Wall -Wextra
#CFLAGS += -g -fsanitize=address
#CFLAGS += -Werror
CFLAGS += -march=native -O3

#GTK_CFLAGS = `pkg-config --cflags gtk+-3.0`
#GTK_LDFLAGS = `pkg-config --libs gtk+-3.0`

$(LIBRARY):
	make -C lib/libft
	make -C lib/libvec
	make -C lib/libobj
	make -C lib/libmalloc

#===========================================================#
#                  //   COMPILATION  \\                     #
#===========================================================#

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C lib/libft
	@make -C lib/libvec
	@make -C lib/libobj
	@make -C lib/libmalloc
	@$(CC) -o $@ $(CFLAGS) $(LINKS) $(LDFLAGS) $(LIBVEC) $(LIBFT) $(LIBOBJ) $(LIBMALLOC)  $(GTK_LDFLAGS) $^ && printf "\033[0;34m" || printf "\033[031m"
	@printf "%-34s \033[1;30m<<--\033[0;0m\n" "$@"

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIRS) $(O_DIR)
	@$(CC) $(CFLAGS) $(LINKS) $(GTK_CFLAGS) -o $@ -c $< \
		&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;33m$@\033[0;0m\n" "$<"

#===========================================================#
#                    //   DELETING  \\                      #
#===========================================================#

.PHONY: clean
clean:
		@echo "\033[36mDeleting ALL Objects...\033[00m"
		@rm -rf $(O_DIR)
		@make clean -C lib/libft
		@make clean -C lib/libvec
		@make clean -C lib/libobj
		@make clean -C lib/libmalloc
		@echo "\033[36mDone\033[00m"

.PHONY: fclean
fclean: clean
		@echo "\033[36mDeleting Project...\033[00m"
		@make fclean -C lib/libft
		@make fclean -C lib/libvec
		@make fclean -C lib/libobj
		@make fclean -C lib/libmalloc
		@rm -f $(NAME)
		@echo "\033[36mDone\033[00m"

#===========================================================#
#                    //   RETRY  \\                         #
#===========================================================#

.PHONY: re
re: fclean all

#===========================================================#
#                   //   RELAUNCH  \\                       #
#===========================================================#

.PHONY: relaunch
relaunch: re
		@./RT

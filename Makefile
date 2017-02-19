# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/31 16:22:08 by ple-lez           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2017/02/19 01:49:17 by ple-lez          ###   ########.fr        #
=======
#    Updated: 2017/02/18 18:16:57 by hsabouri         ###   ########.fr        #
>>>>>>> e63ea7024410fda23945a32e3585654cf3105e57
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
C_DIR = sources
O_DIR = objects

LINKS = -I$(H_DIR)

C_FILES = $(shell find $(C_DIR) -type f -print | grep "\.c")
C_DIRS = $(shell find $(C_DIR) -type d -print)

O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

LIBFT = libft/libft.a
LDFALGS += -L./libft/

LIBVEC = libvec/libvect.a
#HFLAGS += -I./libvec/includes/
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

CC = gcc
CFLAGS = -Wall -Wextra
#CFLAGS += -Werror
CFLAGS += -march=native -O3

$(LIBRARY):
	make -C libft
	make -C libvec

#===========================================================#
#                  //   COMPILATION  \\                     #
#===========================================================#

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@make -C libvec
	@$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBVEC) $(LIBFT) $^ && printf "\033[0;34m" || printf "\033[031m"
	@printf "%-34s \033[1;30m<<--\033[0;0m\n" "$@"

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIRS) $(O_DIR)
	@gcc $(FLAGS) $(LINKS) $(HFLAGS) -I $(LIBVEC) -I $(LIBFT) -o $@ -c $< \
		&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;33m$@\033[0;0m\n" "$<"

#===========================================================#
#                    //   DELETING  \\                      #
#===========================================================#

.PHONY: clean
clean:
		@echo "\033[36mDeleting ALL Objects...\033[00m"
		@rm -rf $(O_DIR)
		@make clean -C libft
		@make clean -C libvec
		@echo "\033[36mDone\033[00m"

.PHONY: fclean
fclean: clean
		@echo "\033[36mDeleting Project...\033[00m"
		@make fclean -C libft
		@make fclean -C libvec
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 11:29:17 by hsabouri          #+#    #+#              #
#    Updated: 2017/04/03 22:46:26 by hsabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===========================================================#
#	   			    //   LIBRARY   \\                       #
#===========================================================#

NAME = libobj.a
MAIN = main.c

#===========================================================#
#                    //   VARIABLE  \\                      #
#===========================================================#

H_DIR = includes
C_DIR = srcs
O_DIR = objects

LINKS = -I$(H_DIR)
LINKS += -I../libft/
LINKS += -I../../includes/
LINKS += -I../libmlx_elcapitan/
LINKS += -I../libvec/includes/
LINKS += -I../libmalloc/

C_FILES = $(shell find $(C_DIR) -type f -print | grep "\.c" | grep -v ".swp")
C_DIRS = $(shell find $(C_DIR) -type d -print)

O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

#============================================================#
#                      //  FLAGS  \\                         #
#============================================================#

FLAGS = -Wextra -Wall
#FLAGS += -g -fsanitize=address
#FLAGS += -Werror
FLAGS += -O3 -march=native

#============================================================#
#                   //  COMPILATION  \\                      #
#============================================================#

.PHONY: all
all: $(NAME)

main:
	$(CC) $(MAIN) $(LINKS) ../libft/libft.a ./libobj.a ../libvec/libvect.a

$(NAME): $(O_FILES)
	@libtool -static -o $@ $^ && printf "\033[0;32m" || printf "\033[031m"
	@printf "%-34s \033[1;30m<<--\033[0;0m\n" "$@"

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIRS) $(O_DIR)
	@gcc $(FLAGS) $(LINKS) -o $@ -c $< \
		&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;34m$@\033[0;0m\n" "$<"

#============================================================#
#                     //  DELETING  \\                       #
#============================================================#

clean:
	@echo "\033[35mDeleting Objects...\033[00m"
	rm -rf objects/list objects/utility objects/print objects/string objects/memory objects/test $(O_DIR)
	@echo "\033[31mDone\033[00m"

fclean: clean
	@echo "\033[35mDeleting Library...\033[00m"
	rm -f $(NAME)
	@echo "\033[31mDone\033[00m"

#============================================================#
#	     			   //  RETRY  \\                         #
#============================================================#

re: fclean all

.PHONY : all clean fclean re

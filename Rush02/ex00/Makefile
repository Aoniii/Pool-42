# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Bruno Da Silva <brda-sil@1E4.42angoulem    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 11:33:12 by Bruno Da Si       #+#    #+#              #
#    Updated: 2022/01/30 17:20:28 by Bruno Da Si      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# BASH COLOR

bold		:= \e[1m
blue		:= \e[34m
red			:= \e[31m
bold_blue	:= $(bold)$(blue)
bold_red	:= $(bold)$(red)
reset		:= \e[0m

# **************************************************************************** #
# Config

# comiplator
CC			:= gcc
# errors flags
CFLAGS		:= -Wall -Wextra -Werror
# name of executable
NAME		:= rush-02

# dir where to search for
SRCDIR		:= src
LIBDIR		:= lib
OBJDIR		:= obj

# joining path dir with wildcarded file
SRC			:= $(wildcard $(SRCDIR)/*.c)

# replacing SRCDIR by OBJDIR in the SRC path list,
# with replacement of *.c file to *.o file
OBJ			= $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRC:%.c=%.o))

# add LIBDIR with -I flag for HEADER
CFLAGS		+= -I$(LIBDIR)

# **************************************************************************** #
# Building rules

all : create_dir $(NAME)

# make obj with src
$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

# make NAME with obj file
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# create OBJDIR, "-p" mean no error if already here
create_dir :
ifeq (,$(wildcard ./$(OBJDIR)))
	@printf "[$(blue)INFO$(reset)] Creating obj dir\n$(bold)"
	mkdir -p obj
	@printf "$(reset)"
endif

# remove OBJDIR
clean :
ifneq (,$(wildcard ./$(OBJDIR)))
	@printf "[$(bold_red)INFO$(reset)] Cleaning obj dir\n$(bold)"
	rm -rf $(OBJDIR)
	@printf "$(reset)"
endif

# remove the executable
fclean : clean
ifneq (,$(wildcard ./$(NAME)))
	@printf "[$(bold_red)INFO$(reset)] Removing executable\n$(bold)"
	rm -f $(NAME)
	@printf "$(reset)"
endif

# Non-File target
.PHONY : all clean fclean
# **************************************************************************** #

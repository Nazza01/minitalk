# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 11:50:25 by Nathanael         #+#    #+#              #
#    Updated: 2022/03/17 13:15:32 by Nathanael        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#							COMPILER & LIBRARIES
CC		=	gcc
PRINTF	=	ft_printf
CFLAGS	=	-Wall -Wextra -Werror -std=c99 -I inc
LIB		=	-I $(PRINTF)/inc -L $(PRINTF) -lftprintf

SRCDIR	=	src
INCDIR	=	inc
BINDIR	=	bin
OBJDIR	=	obj

RM		=	rm -rf
MKDIR	=	mkdir -p
#							MAKEFILE COMMANDS
all: dirs
	@$(MAKE) -C $(PRINTF)
	@$(CC) $(CFLAGS) $(LIB) $(SRCDIR)/server.c -o $(BINDIR)/server
	@$(CC) $(CFLAGS) $(LIB) $(SRCDIR)/client.c -o $(BINDIR)/client
	@clear
	@echo "Compiled: Server & Client"

dirs:
	@$(MKDIR) $(OBJDIR)
	@$(MKDIR) $(BINDIR)
	@clear
	@echo "Made Bin and Obj directories"

clean:
	@$(MAKE) -C $(PRINTF) clean
	@$(RM) $(OBJDIR) $(BINDIR)
	@clear
	@echo "Cleaned minitalk and ft_printf"

fclean: clean
	@$(MAKE) -C $(PRINTF) fclean
	@clear
	@echo "Server, Client & printf: Cleaned"

re: fclean all
	@echo "Cleaned and remade files"

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 20:21:14 by nervin            #+#    #+#              #
#    Updated: 2022/01/29 16:35:25 by Nathanael        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#							COMPILER & LIBRARIES
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBFT	=	libft
NAME 	=	libftprintf.a

#							DIRECTORIES & FILES
SRCDIR	=	src
OBJDIR	=	obj
INCDIR	=	inc

FILES	=	ft_check.c ft_ischaracter.c ft_ishex.c ft_isint.c ft_isperc.c \
ft_ispointer.c ft_isstring.c ft_isunsigned.c ft_numlen.c ft_printf.c
SRC		=	$(addprefix $(SRCDIR)/,$(FILES))
OBJ		=	$(addprefix $(OBJDIR)/,$(FILES:.c=.o))

#							MAKEFILE COMMANDS
all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/ft_printf.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
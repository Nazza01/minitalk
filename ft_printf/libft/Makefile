# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nervin <nervin@student.42adel.org.au >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 09:39:11 by nervin            #+#    #+#              #
#    Updated: 2021/10/07 12:19:58 by nervin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#							FILES TO SEARCH									   #
F		=ft_strdup ft_calloc  ft_strchr ft_bzero ft_strnstr ft_atoi ft_tolower \
ft_toupper ft_strlcpy ft_strlen ft_strlcat ft_strrchr ft_strncmp ft_memchr \
ft_memset ft_memcmp ft_memcpy ft_memmove ft_split ft_strtrim ft_strmapi \
ft_substr ft_striteri ft_putnbr_fd ft_itoa ft_putchar_fd ft_putendl_fd \
ft_putstr_fd ft_strjoin ft_isprint ft_isascii ft_isdigit ft_isalpha ft_isalnum 

B		=ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

#						COMPILE, OBJECTS & DIRECTORIES						   #
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR 		= ar rcs
rm		= rm -f
NAME	= libft.a

SRC_DIR	= ./
OBJ_DIR	= ./

SRC		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(F)))
BON		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(B)))

OBJ		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(F)))
OBJ_BON	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(B)))

# 									RULES									   #
.c.o: $(SRC)
	$(CC) $(CFLAGS) -g -I . -c -o $@ $<

$(NAME): $(OBJ)
	$(AR) $@ $^

bonus: $(OBJ_BON)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_BON)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
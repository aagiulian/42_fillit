# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkantzer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 10:31:32 by mkantzer          #+#    #+#              #
#    Updated: 2016/11/17 17:07:04 by mkantzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
SDIR = srcs
IDIR = includes
LDIR = includes/libft
LIB = includes/libft/libft.a

SRC_FILES = main.c \
			check_file.c
SRC = $(addprefix $(SDIR)/, $(SRC_FILES))

INCLUDES = -I $(LDIR) -I $(IDIR)
LIBLINK = -L $(LDIR) -lft
CFLAGS = -Wall -Werror -Wextra

all: $(LIB) $(NAME)

$(NAME): $(LIB) $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBLINK) $(INCLUDES)

$(LIB):
	make -C $(LDIR)

.PHONY: clean fclean

clean:
	rm -f $(IDIR)/%.gch
	make -C $(LDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LDIR) fclean

re: fclean all

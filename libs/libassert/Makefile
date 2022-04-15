# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 09:32:16 by susami            #+#    #+#              #
#    Updated: 2022/04/15 09:40:11 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR	=	objs
CFLAGS	=	-Wall -Werror -Wextra
SRCS	=	libassert.c
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME	=	libassert.a
RM		=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs libassert.a $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

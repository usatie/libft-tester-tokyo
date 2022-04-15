# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 09:49:28 by susami            #+#    #+#              #
#    Updated: 2022/04/15 11:26:32 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR	=	../
LIBFT		=	$(LIBFT_DIR)libft.a
LIBS		= 	$(LIBFT) ./libs/*/*.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	run-test
INCS	=	./includes\
			./libs/libassert\
			$(LIBFT_DIR)
SRCS	=	srcs/*.c
OBJS	=	$(SRCS:%.c=$(OUT_O_DIR)/%.o)
OBJ_DIR	=	objs
FUNCS	=	atoi\
			calloc

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) 
	$(CC) -o $(NAME) $(CFLAGS)
	./$(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< $(LIBFT) -I $(INCS) -o $@ $(CFLAGS)

clean:
	@$(RM) $(OUT_O_DIR)/*.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@echo "------------------------------Checking restrict keyword usage------------------------------"
	cat $(LIBFT_DIR)*.c | egrep '\.c|restrict' | grep -B 1 'restrict'
	@echo "------------------------------Checking protect------------------------------"
	cat $(LIBFT_DIR)*.c | egrep 'protect|\.c' | grep -B 1 'protect'
	@echo "------------------------------Checking included headers------------------------------"
	cat $(LIBFT_DIR)*.c | egrep '<*.h>|\.c' | grep -B 1 '<*.h>'
	@echo "------------------------------Checking static methods...------------------------------"
	nm $(LIBFT) | egrep "T _[a-z]|libft.a"
	@echo "------------------------------Checking unallowed methods------------------------------"
	nm $(LIBFT) | egrep "U _[a-z]|libft.a" | grep -v "U _ft_" | grep -B 1 'U _[a-z]'
	@echo "------------------------------Checking norminette------------------------------"
	norminette $(LIBFT_DIR)

atoi: $(LIBFT)
	$(CC) srcs/test_ft_$@.c $(LIBS) $(addprefix -I , $(INCS)) -o $(NAME) $(CFLAGS)
	./$(NAME)

.PHONY: all clean fclean re bonus norm test clone

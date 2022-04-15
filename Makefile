# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 09:49:28 by susami            #+#    #+#              #
#    Updated: 2022/04/15 17:01:21 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR		=	../
LIBFT			=	$(LIBFT_DIR)libft.a
LIBASSERT_DIR	=	./libs/libassert/
LIBASSERT		=	$(LIBASSERT_DIR)libassert.a
LIBS			= 	$(LIBFT) ./libs/*/*.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
INCS			=	./includes\
					./libs/libassert\
					$(LIBFT_DIR)
SRCS			=	srcs/*.c
OBJS			=	$(SRCS:%.c=$(OUT_O_DIR)/%.o)
OBJ_DIR			=	objs
FUNCS			=	isalpha\
					isdigit\
					isalnum\
					isascii\
					isprint\
					strlen\
					atoi\
					calloc
ERROR_LOG		=	error.log

all: start_tests $(FUNCS)

start_tests: $(LIBFT) $(LIBASSERT)
	@$(RM) $(ERROR_LOG)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBASSERT):
	$(MAKE) -C ./libs/libassert

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< $(LIBFT) -I $(INCS) -o $@ $(CFLAGS)

clean:
	@$(RM) $(OUT_O_DIR)/*.o $(ERROR_LOG)

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

$(FUNCS): $(LIBFT) $(LIBASSERT)
	@printf "ft_$@: "
	@$(CC) srcs/test_ft_$@.c $(LIBS) $(addprefix -I , $(INCS)) -o a.out $(CFLAGS) && ./a.out 2>>$(ERROR_LOG) && $(RM) a.out
	@printf "\n"

.PHONY: all clean fclean re bonus norm test clone

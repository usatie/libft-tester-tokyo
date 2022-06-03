# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 09:49:28 by susami            #+#    #+#              #
#    Updated: 2022/06/03 13:17:15 by susami           ###   ########.fr        #
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
					$(LIBFT_DIR)\

SRCS			=	srcs/*.c
OBJS			=	$(SRCS:%.c=$(OUT_O_DIR)/%.o)
OBJ_DIR			=	objs
FUNCS_PART1		=	isalpha\
					isdigit\
					isalnum\
					isascii\
					isprint\
					strlen\
					memset\
					bzero\
					memcpy\
					memmove\
					strlcpy\
					strlcat\
					toupper\
					tolower\
					strchr\
					strrchr\
					strncmp\
					memchr\
					memcmp\
					strnstr\
					atoi\
					calloc\
					strdup\

FUNCS_PART2		=	substr\
					strjoin\
					strtrim\
					split\
					itoa\
					strmapi\
					striteri\
					putchar_fd\
					putstr_fd\
					putendl_fd\
					putnbr_fd\

FUNCS_BONUS		=	lstnew\
					lstadd_front\
					lstsize\
					lstlast\
					lstadd_back\
					lstdelone\
					lstclear\
					lstiter\
					lstmap\

FUNCS_EXTRA		=	strcmp\
					
FUNCS			= $(FUNCS_PART1) $(FUNCS_PART2)
ERROR_LOG		=	error.log

all: start_tests $(FUNCS)
	@find . -name "*.log" -size 0 -exec rm {} \;
	@[ ! -f $(ERROR_LOG) ] &&\
		printf "\e[32m\n\n------------------------------------------------------------\
		\n[MANDATORY PARTS] All tests passed successfully! Congratulations :D\n\e[m" ||\
		printf "\e[31m\n\n------------------------------------------------------------\
		\nSome tests failed. Please see error.log for more detailed information.\n\e[m"

bonus: start_bonus_tests $(FUNCS_BONUS)
	@find . -name "*.log" -size 0 -exec rm {} \;
	@[ ! -f $(ERROR_LOG) ] &&\
		printf "\e[32m\n\n------------------------------------------------------------\
		\n[BONUS PARTS] All tests passed successfully! Congratulations :D\n\e[m" ||\
		printf "\e[31m\n\n------------------------------------------------------------\
		\nSome tests failed. Please see error.log for more detailed information.\n\e[m"

extra: start_bonus_tests $(FUNCS_EXTRA)
	@find . -name "*.log" -size 0 -exec rm {} \;
	@[ ! -f $(ERROR_LOG) ] &&\
		printf "\e[32m\n\n------------------------------------------------------------\
		\n[EXTRA] All tests passed successfully! Congratulations :D\n\e[m" ||\
		printf "\e[31m\n\n------------------------------------------------------------\
		\nSome tests failed. Please see error.log for more detailed information.\n\e[m"
start_tests:
	@$(RM) $(ERROR_LOG)
	make -C $(LIBFT_DIR)
	make -C ./libs/libassert
	@#make -C $(LIBFT_DIR) bonus

start_bonus_tests:
	@$(RM) $(ERROR_LOG)
	make -C $(LIBFT_DIR) bonus
	make -C ./libs/libassert

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBASSERT):
	make -C ./libs/libassert

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< $(LIBFT) -I $(INCS) -o $@ $(CFLAGS)

clean:
	@$(RM) $(OUT_O_DIR)/*.o $(ERROR_LOG)

fclean: clean
	@$(MAKE) -C ./libs/libassert re

re: fclean all

norm:
	@echo "------------------------------Checking restrict keyword usage------------------------------"
	cat $(LIBFT_DIR)*.c | egrep '\.c|restrict' | grep -B 1 'restrict' && printf "\e[31mYour implementation may contains unallowed restrict keyword.\n\e[m" || printf "\e[32mOK :D\n\e[m"
	@echo "------------------------------Checking included headers------------------------------"
	cat $(LIBFT_DIR)*.c | egrep '<*.h>|\.c' | grep -B 1 '<*.h>' || printf "\e[32mheader inclusion OK :D\n\e[m"
	@echo "------------------------------Checking static methods...------------------------------"
	nm $(LIBFT) -A | grep "T _" | sed -e 's/: .* T _.*//' | sed -e 's/..\/libft.a://' | uniq -c | grep -v ' 1 ' && printf "\e[31mNon static functions found in your imlementation!\n\e[m" || printf "\e[32mOK :D\n\e[m"
	@echo "------------------------------Checking unallowed methods------------------------------"
	nm $(LIBFT) -A | egrep "U _[a-z]" | egrep -v "U _ft_[a-z]" | sed -e 's/..\/libft.a://'
	@printf "\e[33mMake sure your implementation does not use unallowed standard functions.\n\e[m"
	@echo "------------------------------Checking norminette------------------------------"
	norminette $(LIBFT_DIR)*.c $(LIBFT_DIR)*.h | grep -v "OK!" || printf "\e[32mnorminette OK :D\n\e[m"

$(FUNCS) $(FUNCS_BONUS) $(FUNCS_EXTRA): $(LIBFT) $(LIBASSERT)
	@printf "ft_$@: "
	@-$(CC) srcs/test_ft_$@.c $(LIBS) $(addprefix -I , $(INCS)) -o a.out $(CFLAGS) 2>>$(ERROR_LOG) && ./a.out 2>>$(ERROR_LOG) && $(RM) a.out || printf "\e[31m[MISSING]\e[m"
	@printf "\n"

.PHONY: all clean fclean re bonus norm test clone

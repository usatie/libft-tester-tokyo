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
LIBFT_00		=	$(LIBFT_DIR)libft00.a
LIBFT_01		=	$(LIBFT_DIR)libft01.a
LIBFT_02		=	$(LIBFT_DIR)libft02.a
LIBASSERT_DIR	=	./libs/libassert/
LIBASSERT		=	$(LIBASSERT_DIR)libassert.a
LIBS			= 	./libs/*/*.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
INCS			=	./includes\
					$(LIBFT_DIR)\

SRCS			=	srcs/*.c
OBJS			=	$(SRCS:%.c=$(OUT_O_DIR)/%.o)
OBJ_DIR			=	objs

FUNCS_LIBFT00	=	isalpha\
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

FUNCS_LIBFT01	=	toupper\
					tolower\
					strchr\
					strrchr\
					strncmp\
					memchr\
					memcmp\
					strnstr\
					atoi\

FUNCS_LIBFT02_1	=	calloc\
					strdup\

FUNCS_LIBFT02_2	=	substr\
					strjoin\
					strtrim\
					split\
					itoa\

FUNCS_LIBFT02	=	$(FUNCS_LIBFT02_1)\
					$(FUNCS_LIBFT02_2)\

FUNCS_PART1		=	$(FUNCS_LIBFT00)\
					$(FUNCS_LIBFT01)\
					$(FUNCS_LIBFT02_1)\

FUNCS_PART2		=	$(FUNCS_LIBFT02_2)\
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

RE_LIBFT00_TARG	=	$(addsuffix .re, $(FUNCS_LIBFT00))
RE_LIBFT01_TARG	=	$(addsuffix .re, $(FUNCS_LIBFT01))
RE_LIBFT02_TARG	=	$(addsuffix .re, $(FUNCS_LIBFT02))

SRCS_LIBFT00	= $(shell ls $(addprefix $(LIBFT_DIR)ft_, $(addsuffix .c, $(FUNCS_LIBFT00))) 2> /dev/null)
SRCS_LIBFT01	= $(shell ls $(addprefix $(LIBFT_DIR)ft_, $(addsuffix .c, $(FUNCS_LIBFT01))) 2> /dev/null)
SRCS_LIBFT02	= $(shell ls $(addprefix $(LIBFT_DIR)ft_, $(addsuffix .c, $(FUNCS_LIBFT02))) 2> /dev/null)

OBJS_LIBFT00	= $(SRCS_LIBFT00:.c=.o)
OBJS_LIBFT01	= $(SRCS_LIBFT01:.c=.o)
OBJS_LIBFT02	= $(SRCS_LIBFT02:.c=.o)

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

libft-00: start_reloaded_tests $(RE_LIBFT00_TARG)
	@find . -name "*.log" -size 0 -exec rm {} \;
	@[ ! -f $(ERROR_LOG) ] &&\
		printf "\e[32m\n\n------------------------------------------------------------\
		\n[Libft-00] All tests passed successfully! Congratulations :D\n\e[m" ||\
		printf "\e[31m\n\n------------------------------------------------------------\
		\nSome tests failed. Please see error.log for more detailed information.\n\e[m"

libft-01: start_reloaded_tests $(RE_LIBFT01_TARG)
	@find . -name "*.log" -size 0 -exec rm {} \;
	@[ ! -f $(ERROR_LOG) ] &&\
		printf "\e[32m\n\n------------------------------------------------------------\
		\n[Libft-01] All tests passed successfully! Congratulations :D\n\e[m" ||\
		printf "\e[31m\n\n------------------------------------------------------------\
		\nSome tests failed. Please see error.log for more detailed information.\n\e[m"

libft-02: start_reloaded_tests $(RE_LIBFT02_TARG)
	@find . -name "*.log" -size 0 -exec rm {} \;
	@[ ! -f $(ERROR_LOG) ] &&\
		printf "\e[32m\n\n------------------------------------------------------------\
		\n[Libft-02] All tests passed successfully! Congratulations :D\n\e[m" ||\
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

start_reloaded_tests:
	@$(RM) $(ERROR_LOG)
	make -C ./libs/libassert

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBFT_00): $(OBJS_LIBFT00)
	ar rc $@ $^

$(LIBFT_01): $(OBJS_LIBFT00) $(OBJS_LIBFT01)
	ar rc $@ $^

$(LIBFT_02): $(OBJS_LIBFT00) $(OBJS_LIBFT01) $(OBJS_LIBFT02)
	ar rc $@ $^

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

norm00: $(LIBFT_00)
	make norm LIBFT=$<
norm01: $(LIBFT_01)
	make norm LIBFT=$<
norm02: $(LIBFT_02)
	make norm LIBFT=$<

$(FUNCS) $(FUNCS_BONUS) $(FUNCS_EXTRA): $(LIBFT) $(LIBASSERT)
	@printf "ft_$@: "
	@-$(CC) srcs/test_ft_$@.c $(LIBFT) $(LIBS) $(addprefix -I , $(INCS)) -o a.out $(CFLAGS) 2>>$(ERROR_LOG) && ./a.out 2>>$(ERROR_LOG) && $(RM) a.out || printf "\e[31m[MISSING]\e[m"
	@printf "\n"

$(RE_LIBFT00_TARG): $(LIBFT_00) $(LIBASSERT)
	@printf "ft_$(basename $@): "
	@-$(CC) srcs/test_ft_$(basename $@).c $(LIBFT_00) $(LIBS) $(addprefix -I , $(INCS)) -o a.out $(CFLAGS) 2>>$(ERROR_LOG) && ./a.out 2>>$(ERROR_LOG) && $(RM) a.out || printf "\e[31m[MISSING]\e[m"
	@printf "\n"

$(RE_LIBFT01_TARG): $(LIBFT_01) $(LIBASSERT)
	@printf "ft_$(basename $@): "
	@-$(CC) srcs/test_ft_$(basename $@).c $(LIBFT_01) $(LIBS) $(addprefix -I , $(INCS)) -o a.out $(CFLAGS) 2>>$(ERROR_LOG) && ./a.out 2>>$(ERROR_LOG) && $(RM) a.out || printf "\e[31m[MISSING]\e[m"
	@printf "\n"

$(RE_LIBFT02_TARG): $(LIBFT_02) $(LIBASSERT)
	@printf "ft_$(basename $@): "
	@-$(CC) srcs/test_ft_$(basename $@).c $(LIBFT_02) $(LIBS) $(addprefix -I , $(INCS)) -o a.out $(CFLAGS) 2>>$(ERROR_LOG) && ./a.out 2>>$(ERROR_LOG) && $(RM) a.out || printf "\e[31m[MISSING]\e[m"
	@printf "\n"

.PHONY: all clean fclean re bonus norm test clone

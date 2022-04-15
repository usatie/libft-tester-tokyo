/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libassert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:34:09 by susami            #+#    #+#             */
/*   Updated: 2022/04/15 12:07:54 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
static size_t	counter = 0;
static void	start_test(void)
{
	printf("%zu.", ++counter);
}

static void	print_ok(void)
{
	printf(ANSI_COLOR_GREEN "OK " ANSI_COLOR_RESET);
}

static void	print_ko(void)
{
	printf(ANSI_COLOR_RED "KO " ANSI_COLOR_RESET);
}

static void print_error(char *fmt, ...)
{
	va_list	args;
	va_start(args, fmt);
	fprintf(stderr, ANSI_COLOR_RED);
	vfprintf(stderr, fmt, args);
	fprintf(stderr, ANSI_COLOR_RESET);
	va_end(args);
}

void	ASSERT_TRUE(bool actual,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (actual == false)
	{
		print_ko();
		print_error("%s failed: ", __func__);
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
		return ;
	}
	else
		print_ok();
}

void	ASSERT_EQ_I(int actual, int expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (actual != expected)
	{
		print_ko();
		print_error("[test %zu] %s failed: (\"%i\") is not equal to expected (\"%i\"). ",
			counter, __func__, actual, expected);
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
		return ;
	}
	else
		print_ok();
}

void	ASSERT_EQ_UI(unsigned int actual, unsigned int expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	if (actual != expected)
	{
		printf("%s failed: (\"%u\") is not equal to expected (\"%u\"). ",
			__func__, actual, expected);
		printf("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
}

void	ASSERT_EQ_L(long actual, long expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	if (actual != expected)
	{
		printf("%s failed: (\"%li\") is not equal to expected (\"%li\"). ",
			__func__, actual, expected);
		printf("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
}

void	ASSERT_EQ_UL(unsigned long actual, unsigned long expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	if (actual != expected)
	{
		printf("%s failed: (\"%lu\") is not equal to expected (\"%lu\"). ",
			__func__, actual, expected);
		printf("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
}

void	ASSERT_EQ_LL(long long actual, long long expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	if (actual != expected)
	{
		printf("%s failed: (\"%lli\") is not equal to expected (\"%lli\"). ",
			__func__, actual, expected);
		printf("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
}

void	ASSERT_EQ_ULL(unsigned long long actual, unsigned long long expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	if (actual != expected)
	{
		printf("%s failed: (\"%llu\") is not equal to expected (\"%llu\"). ",
			__func__, actual, expected);
		printf("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
}

void	ASSERT_EQ_SIZE(size_t actual, size_t expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	if (actual != expected)
	{
		printf("%s failed: (\"%zu\") is not equal to expected (\"%zu\"). ",
			__func__, actual, expected);
		printf("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
}

void	ASSERT_EQ_STR(char *actual, char *expected, size_t size,
	char *caller_file, const char *caller_func, int caller_line)
{
	if (strncmp(actual, expected, size) != 0)
	{
		printf("%s failed: (\"%s\") is not equal to expected (\"%s\"). ",
			__func__, actual, expected);
		printf("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
}

static const char	*g_base16 = "0123456789abcdef";

static void	hexdump(void *p, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	char			c;

	ptr = (unsigned char *)p;
	i = 0;
	while (i < size)
	{
		c = *(ptr + i);
		printf("%c%c", g_base16[(c >> 4) & 0x0f], g_base16[c & 0x0f]);
		i++;
	}
}

void	ASSERT_EQ_MEM(void *actual, void *expected, size_t size,
	char *caller_file, const char *caller_func, int caller_line)
{
	if (memcmp(actual, expected, size) != 0)
	{
		printf("%s failed: (\"", __func__);
		hexdump(actual, size);
		printf("\") is not equal to expected (\"");
		hexdump(expected, size);
		printf("\"). ");
		printf("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
}

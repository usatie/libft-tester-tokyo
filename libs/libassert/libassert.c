/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libassert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:34:09 by susami            #+#    #+#             */
/*   Updated: 2022/04/22 11:06:29 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <malloc/malloc.h>
#define ANSI_COLOR_RED     "\x1b[1;31m"
#define ANSI_COLOR_GREEN   "\x1b[1;32m"
#define ANSI_COLOR_YELLOW  "\x1b[1;33m"
#define ANSI_COLOR_BLUE    "\x1b[1;34m"
#define ANSI_COLOR_MAGENTA "\x1b[1;35m"
#define ANSI_COLOR_CYAN    "\x1b[1;36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* Function for printing out test index, OK/KO, errors */
static size_t	counter = 0;
static void	start_test(void)
{
	printf("%zu.", ++counter);
	fflush(stdout);
}

static void	print_ok(void)
{
	printf(ANSI_COLOR_GREEN "OK " ANSI_COLOR_RESET);
	fflush(stdout);
}

static void	print_ko(void)
{
	printf(ANSI_COLOR_RED "KO " ANSI_COLOR_RESET);
	fflush(stdout);
}

static void print_error(char *fmt, ...)
{
	va_list	args;
	va_start(args, fmt);
	//fprintf(stderr, ANSI_COLOR_RED);
	vfprintf(stderr, fmt, args);
	//fprintf(stderr, ANSI_COLOR_RESET);
	va_end(args);
}

/* Function for printing out memory as hex to stderr*/
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
		print_error("%c%c", g_base16[(c >> 4) & 0x0f], g_base16[c & 0x0f]);
		i++;
	}
}

/* Assert functions for testing */
void	ASSERT_TRUE(bool actual,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (actual == false)
	{
		print_ko();
		print_error("[test %zu] %s failed: ", __func__);
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
	start_test();
	if (actual != expected)
	{
		print_ko();
		print_error("[test %zu] %s failed: (\"%u\") is not equal to expected (\"%u\"). ",
			__func__, actual, expected);
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
	else
		print_ok();
}

void	ASSERT_EQ_L(long actual, long expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (actual != expected)
	{
		print_ko();
		print_error("[test %zu] %s failed: (\"%li\") is not equal to expected (\"%li\"). ",
			counter, __func__, actual, expected);
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
	else
		print_ok();
}

void	ASSERT_EQ_UL(unsigned long actual, unsigned long expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (actual != expected)
	{
		print_ko();
		print_error("[test %zu] %s failed: (\"%lu\") is not equal to expected (\"%lu\"). ",
			counter, __func__, actual, expected);
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
	else
		print_ok();
}

void	ASSERT_EQ_LL(long long actual, long long expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (actual != expected)
	{
		print_ko();
		print_error("[test %zu] %s failed: (\"%lli\") is not equal to expected (\"%lli\"). ",
			counter, __func__, actual, expected);
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
	else
		print_ok();
}

void	ASSERT_EQ_ULL(unsigned long long actual, unsigned long long expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (actual != expected)
	{
		print_ko();
		print_error("[test %zu] %s failed: (\"%llu\") is not equal to expected (\"%llu\"). ",
			counter, __func__, actual, expected);
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
	else
		print_ok();
}

void	ASSERT_EQ_SIZE(size_t actual, size_t expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (actual != expected)
	{
		print_ko();
		print_error("[test %zu] %s failed: (\"%zu\") is not equal to expected (\"%zu\"). ",
			counter, __func__, actual, expected);
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
	else
		print_ok();
}

void	ASSERT_EQ_STR(char *actual, char *expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (expected == NULL || actual == NULL)
	{
		if (expected != actual)
		{
			print_ko();
			print_error("[test %zu] %s failed: \"%p\" is not equal to expected \"%p\"", counter, __func__, actual, expected);
			print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
		}
		else
			print_ok();
		return ;
	}

	if (strcmp(actual, expected) != 0)
	{
		print_ko();
		print_error("[test %zu] %s failed: (\"%s\") is not equal to expected (\"%s\"). ",
			counter, __func__, actual, expected);
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
	else
		print_ok();
}

void	ASSERT_EQ_MALLOC_SIZE(void *actual, void *expected,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (expected == NULL || actual == NULL)
	{
		if (expected != actual)
		{
			print_ko();
			print_error("[test %zu] %s failed: \"%p\" is not equal to expected \"%p\"", counter, __func__, actual, expected);
			print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
		}
		else
			print_ok();
		return ;
	}
		
	if (malloc_size(actual) != malloc_size(expected))
	{
		print_ko();
		print_error("[test %zu] %s failed: malloc_size \"%i\" is not equal to expected \"%i\"\n", counter, __func__, malloc_size(actual), malloc_size(expected));
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
	else
		print_ok();
}
void	ASSERT_EQ_MEM(void *actual, void *expected, size_t size,
	char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (expected == NULL || actual == NULL)
	{
		if (expected != actual)
		{
			print_ko();
			print_error("[test %zu] %s failed: \"%p\" is not equal to expected \"%p\"", counter, __func__, actual, expected);
			print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
		}
		else
			print_ok();
		return ;
	}
		
	if (memcmp(actual, expected, size) != 0)
	{
		print_ko();
		print_error("[test %zu] %s failed: hexdump (\"", counter, __func__);
		hexdump(actual, size);
		print_error("\") is not equal to expected (\"");
		hexdump(expected, size);
		print_error("\"). ");
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
	else
		print_ok();
}

void	ASSERT_EQ_PTR(void *actual, void *expected,
			char *caller_file, const char *caller_func, int caller_line)
{
	start_test();
	if (actual != expected)
	{
		print_ko();
		print_error("[test %zu] %s failed: (\"%p\") is not equal to expected (\"%p\"). ",
			counter, __func__, actual, expected);
		print_error("func %s at file %s, line %d\n",
			caller_func, caller_file, caller_line);
	}
	else
		print_ok();
}

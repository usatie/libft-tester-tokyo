/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunusami <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:07:48 by shunusam          #+#    #+#             */
/*   Updated: 2022/04/19 09:08:29 by shunusam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"
#include "libassert.h"

static int (*f)(int) = NULL;
static void F(unsigned int i, char *s) { (void)i; *s = f(*s); };
static int plus_one(int c) { return (c + 1); }

static char buf[100] = {};
static void tobuf(unsigned int i, char *str) {
    static size_t   idx = 0;
    (void)i;

    buf[idx++] = *str;
}

int main(void)
{
    char str[] = "abcde";

    f = toupper; ft_striteri(str, F);
    /* 1 */ ASSERT_EQ_STR(str, "ABCDE");
    f = plus_one; ft_striteri(str, F);
    /* 2 */ ASSERT_EQ_STR(str, "BCDEF");
    f = tolower; ft_striteri(str, F);
    /* 3 */ ASSERT_EQ_STR(str, "bcdef");
    f = plus_one; ft_striteri(str, F);
    /* 4 */ ASSERT_EQ_STR(str, "cdefg");
    f = toupper; ft_striteri(str, F);
    /* 5 */ ASSERT_EQ_STR(str, "CDEFG");

    bzero(buf, 100);
    ft_striteri("hello", tobuf);
    /* 6 */ ASSERT_EQ_STR(buf, "hello");
    ft_striteri(" world", tobuf);
    /* 7 */ ASSERT_EQ_STR(buf, "hello world");
    ft_striteri(" 42!", tobuf);
    /* 8 */ ASSERT_EQ_STR(buf, "hello world 42!");

}

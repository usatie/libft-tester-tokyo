/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunusami <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:08:38 by shunusam          #+#    #+#             */
/*   Updated: 2022/05/02 10:09:46 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int (*f)(int) = NULL;
static char F(unsigned int i, char c) { (void)i; return (f(c)); };
static int plus_one(int c) { return (c + 1); }

int main(void)
{
    f = toupper;
    /* 1 */ ASSERT_EQ_STR(ft_strmapi("abcde", F), "ABCDE");
    /* 2 */ ASSERT_EQ_STR(ft_strmapi("Hello World!", F), "HELLO WORLD!");
    /* 3 */ ASSERT_EQ_STR(ft_strmapi("12345", F), "12345");
    f = tolower;
    /* 4 */ ASSERT_EQ_STR(ft_strmapi("ABCDE", F), "abcde");
    /* 5 */ ASSERT_EQ_STR(ft_strmapi("Hello World!", F), "hello world!");
    /* 6 */ ASSERT_EQ_STR(ft_strmapi("12345", F), "12345");
    f = plus_one;
    /* 7 */ ASSERT_EQ_STR(ft_strmapi("ABCDE", F), "BCDEF");
    /* 8 */ ASSERT_EQ_STR(ft_strmapi("Hello World!", F), "Ifmmp!Xpsme\"");
    /* 9 */ ASSERT_EQ_STR(ft_strmapi("12345", F), "23456");
}

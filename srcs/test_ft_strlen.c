/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:58:08 by susami            #+#    #+#             */
/*   Updated: 2022/04/15 17:10:29 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"
#include "libassert.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_strlen(""), strlen(""));
	/* 2 */ ASSERT_EQ_I(ft_strlen("hello"), strlen("hello"));
	/* 3 */ ASSERT_EQ_I(ft_strlen("hello world"), strlen("hello world"));
	char *s;
	s = calloc((size_t)INT_MAX + 10, sizeof(char));
	memset(s, 1, (size_t)INT_MAX - 5);
	/* 4 very long */ ASSERT_EQ_I(ft_strlen(s), strlen(s));
	memset(s, 1, (size_t)INT_MAX + 5);
	/* 5 int overflow */ ASSERT_EQ_I(ft_strlen(s), strlen(s));
	for (int i = 1; i < INT_MAX; i++)
		s[i - 1] = i;
	/* 6 various values */ ASSERT_EQ_I(ft_strlen(s), strlen(s));
	// TODO: assert segmentation fault
	// /* 7 */ ASSERT_EQ_I(ft_strlen(NULL), strlen(NULL));
}

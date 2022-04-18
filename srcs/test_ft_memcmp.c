/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:56:22 by susami            #+#    #+#             */
/*   Updated: 2022/04/18 23:48:17 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "libft.h"
#include "libassert.h"

int	main(void)
{
	int	len = 30;
	char *str = calloc(30, sizeof(char));
	char *cmp = calloc(30, sizeof(char));
	memcpy(str, "libft-test-tokyo", 16);
	memcpy(cmp, "libft-test-tokyo", 16);
	memcpy(str + 20, "acdfg", 5);
	memcpy(cmp + 20, "acdfg", 5);
	/* 1 ~ 31 */
	for (int i = 0; i <= len; i++)
		ASSERT_EQ_I(ft_memcmp(str, cmp, i), memcmp(str, cmp, i));
	/* 32 ~ 93 */
	for (int i = 0; i <= len; i++)
	{
		cmp = strndup(str, i);
		ASSERT_EQ_I(ft_memcmp(str, cmp, i), memcmp(str, cmp, i));
		ASSERT_EQ_I(ft_memcmp(str, cmp, len), memcmp(str, cmp, len));
		free(cmp);
	}
	char *cmp2 = calloc(30, sizeof(char));
	strlcpy(cmp2, "libft", sizeof(char));
	cmp2[5] = CHAR_MIN;
	/* 94 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
	cmp2[5] = -42;
	/* 95 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
	cmp2[5] = 0;
	/* 96 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
	cmp2[5] = 42;
	/* 97 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
	cmp2[5] = CHAR_MAX;
	/* 98 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));

	strlcpy(cmp2, "libft-test-tokyo", sizeof(char));
	strlcpy(cmp2 + 20, "acdfg", sizeof(char));
	cmp2[29] = CHAR_MIN;
	/* 99 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
	cmp2[29] = -42;
	/* 100 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
	cmp2[29] = 0;
	/* 101 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
	cmp2[29] = 42;
	/* 102 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
	cmp2[29] = CHAR_MAX;
	/* 103 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
	return (0);
}

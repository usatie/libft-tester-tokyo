/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:57:05 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:09:30 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char *dst1 = calloc(10, sizeof(char));
	char *dst2 = calloc(10, sizeof(char));
	char *src1 = calloc(10, sizeof(char));
	char *src2 = calloc(10, sizeof(char));
	memset(src1, 'z', 9);
	memset(src2, 'z', 9);

	/* 1 */ ASSERT_EQ_I(ft_strlcpy(dst1, "", 10), strlcpy(dst2, "", 10));
	/* 2 */ ASSERT_EQ_STR(dst1, dst2);
	/* 3 */ ASSERT_EQ_I(ft_strlcpy(dst1, "hello", 10), strlcpy(dst2, "hello", 10));
	/* 4 */ ASSERT_EQ_STR(dst1, dst2);
	/* 5 */ ASSERT_EQ_I(ft_strlcpy(dst1, "world", 10), strlcpy(dst2, "world", 10));
	/* 6 */ ASSERT_EQ_STR(dst1, dst2);
	/* 7 */ ASSERT_EQ_I(ft_strlcpy(dst1, src1, 0), strlcpy(dst2, src2, 0));
	/* 8 */ ASSERT_EQ_STR(dst1, dst2);
	/* 9 */ ASSERT_EQ_I(ft_strlcpy(dst1, src1, 10), strlcpy(dst2, src2, 10));
	/* 10 */ ASSERT_EQ_I(ft_strlcpy(NULL, "", 0), strlcpy(NULL, "", 0));
	bzero(dst1, 10);
	bzero(dst2, 10);

	char *s1 = "hello";
	char *s2 = "hello wonderfule world!";
	/* 11 ~ 20 */
	for (size_t i = 0; i < strlen(s1); i++)
	{
		ASSERT_EQ_I(ft_strlcpy(dst1, s1, i), strlcpy(dst2, s1, i));
		ASSERT_EQ_STR(dst1, dst2);
	}
	/* 21 ~ 40 */
	for (int i = 0; i < 10; i++)
	{
		ASSERT_EQ_I(ft_strlcpy(dst1, s2, 10), strlcpy(dst2, s2, 10));
		ASSERT_EQ_STR(dst1, dst2);
	}
	/* 41 */ ASSERT_EQ_I(ft_strlcpy(dst1, "", 10), strlcpy(dst2, "", 10));
	/* 42 */ ASSERT_EQ_STR(dst1, dst2);
	/* 43 */ ASSERT_EQ_I(ft_strlcpy(dst1, "hello", 10), strlcpy(dst2, "hello", 10));
	/* 44 */ ASSERT_EQ_STR(dst1, dst2);
	/* 45 */ ASSERT_EQ_I(ft_strlcpy(dst1, "world", 10), strlcpy(dst2, "world", 10));
	/* 46 */ ASSERT_EQ_STR(dst1, dst2);
	/* 47 */ ASSERT_EQ_I(ft_strlcpy(dst1, src1, 0), strlcpy(dst2, src2, 0));
	/* 48 */ ASSERT_EQ_STR(dst1, dst2);
	/* 49 */ ASSERT_EQ_I(ft_strlcpy(dst1, src1, 10), strlcpy(dst2, src2, 10));
	/* 50 */ ASSERT_EQ_I(ft_strlcpy(NULL, "", 0), strlcpy(NULL, "", 0));
}

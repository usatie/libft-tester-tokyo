/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:16:21 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:09:22 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char *dst1 = calloc(100, sizeof(char));
	char *dst2 = calloc(100, sizeof(char));
	/* 1 */ ASSERT_EQ_I(ft_strlcat(dst1, "", 100), strlcat(dst2, "", 100));
	/* 2 */ ASSERT_EQ_STR(dst1, dst2);
	/* 3 */ ASSERT_EQ_I(ft_strlcat(dst1, "hello", 100), strlcat(dst2, "hello", 100));
	/* 4 */ ASSERT_EQ_STR(dst1, dst2);
	/* 5 */ ASSERT_EQ_I(ft_strlcat(dst1, "world", 100), strlcat(dst2, "world", 100));
	/* 6 */ ASSERT_EQ_STR(dst1, dst2);
	char *src1 = calloc(100, sizeof(char));
	char *src2 = calloc(100, sizeof(char));
	for (int i = 0; i < 99; i++)
	{
		src1[i] = i + 1;
		src2[i] = i + 1;
	}
	/* 7 */ ASSERT_EQ_I(ft_strlcat(dst1, src1, 0), strlcat(dst2, src2, 0));
	/* 8 */ ASSERT_EQ_STR(dst1, dst2);
	/* 9 */ ASSERT_EQ_I(ft_strlcat(dst1, src1, 10), strlcat(dst2, src2, 10));
	/* 10 */ ASSERT_EQ_STR(dst1, dst2);
	/* 11 */ ASSERT_EQ_I(ft_strlcat(dst1, src1, 50), strlcat(dst2, src2, 50));
	/* 12 */ ASSERT_EQ_STR(dst1, dst2);
	/* 13 */ ASSERT_EQ_I(ft_strlcat(dst1, src1, 100), strlcat(dst2, src2, 100));
	/* 14 */ ASSERT_EQ_STR(dst1, dst2);
	/* 15 */ ASSERT_EQ_I(ft_strlcat(dst1, src1, 10), strlcat(dst2, src2, 10));
	/* 16 */ ASSERT_EQ_STR(dst1, dst2);
	/* 17 */ ASSERT_EQ_I(ft_strlcat(dst1, src1, 100), strlcat(dst2, src2, 100));
	/* 18 */ ASSERT_EQ_STR(dst1, dst2);
	/* 19 */ ASSERT_EQ_I(ft_strlcat(NULL, src1, 0), strlcat(NULL, src2, 0));
}

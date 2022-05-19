/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:17:32 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:45:43 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char *str = "libft-test-tokyo";
	char *cmp = "libft-test-tokyo";
	int	len = strlen(str);
	/* 1 ~ 17 */
	for (int i = 0; i <= len; i++)
		ASSERT_EQ_I(ft_strncmp(str, cmp, i), strncmp(str, cmp, i));
	/* 18 ~ 51 */
	for (int i = 0; i <= len; i++)
	{
		cmp = strndup(str, i);
		ASSERT_EQ_I(ft_strncmp(str, cmp, i), strncmp(str, cmp, i));
		ASSERT_EQ_I(ft_strncmp(str, cmp, len), strncmp(str, cmp, len));
		free(cmp);
	}
	char *cmp2 = calloc(10, 1);
	strlcpy(cmp2, "libft", 10);
	cmp2[5] = CHAR_MIN;
	/* 52 */ ASSERT_EQ_I(ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
	cmp2[5] = -42;
	/* 53 */ ASSERT_EQ_I(ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
	cmp2[5] = 0;
	/* 54 */ ASSERT_EQ_I(ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
	cmp2[5] = 42;
	/* 55 */ ASSERT_EQ_I(ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
	cmp2[5] = CHAR_MAX;
	/* 56 */ ASSERT_EQ_I(ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
	/* 57 */ ASSERT_EQ_I(ft_strncmp("hello", NULL, 0), strncmp("hello", NULL, 0));
	/* 58 */ ASSERT_EQ_I(ft_strncmp(NULL, "hello", 0), strncmp(NULL, "hello", 0));
	/* 59 */ ASSERT_EQ_I(ft_strncmp(NULL, NULL, 0), strncmp(NULL, NULL, 0));
	return (0);
}

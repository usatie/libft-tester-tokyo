/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:31:55 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:10:32 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char *s = "libft-test-tokyo";
	/* 1 */ ASSERT_EQ_STR(ft_substr(s, 0, 100), s);
	/* 3 */ ASSERT_EQ_STR(ft_substr(s, 5, 100), s + 5);
	/* 3 */ ASSERT_EQ_STR(ft_substr(s, 10, 100), s + 10);
	/* 4 */ ASSERT_EQ_STR(ft_substr(s, 15, 100), s + 15);
	/* 5 */ ASSERT_EQ_STR(ft_substr(s, 20, 100), "");
	/* 6 */ ASSERT_EQ_STR(ft_substr(s, 0, 5), "libft");
	/* 7 */ ASSERT_EQ_STR(ft_substr(s, 5, 5), "-test");
	/* 8 */ ASSERT_EQ_STR(ft_substr(s, 10, 5), "-toky");
	/* 9 */ ASSERT_EQ_STR(ft_substr(s, 15, 5), "o");
	/* 10 */ ASSERT_EQ_STR(ft_substr(s, 20, 5), "");
	/* 11 */ ASSERT_EQ_STR(ft_substr(s, 0, 0), "");
	/* 12 */ ASSERT_EQ_STR(ft_substr(s, 5, 0), "");
	/* 13 */ ASSERT_EQ_STR(ft_substr(s, 10, 0), "");
	/* 14 */ ASSERT_EQ_STR(ft_substr(s, 15, 0), "");
	/* 15 */ ASSERT_EQ_STR(ft_substr(s, 20, 0), "");
}

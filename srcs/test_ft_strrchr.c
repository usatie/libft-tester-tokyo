/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 07:44:16 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:10:17 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char *s = "libft-test-tokyo";
	/* 1 */ ASSERT_EQ_STR(ft_strrchr(s, 'l'), strrchr(s, 'l'));
	/* 2 */ ASSERT_EQ_STR(ft_strrchr(s, 'i'), strrchr(s, 'i'));
	/* 3 */ ASSERT_EQ_STR(ft_strrchr(s, 'b'), strrchr(s, 'b'));
	/* 4 */ ASSERT_EQ_STR(ft_strrchr(s, 'f'), strrchr(s, 'f'));
	/* 5 */ ASSERT_EQ_STR(ft_strrchr(s, 't'), strrchr(s, 't'));
	/* 6 */ ASSERT_EQ_STR(ft_strrchr(s, '-'), strrchr(s, '-'));
	/* 7 */ ASSERT_EQ_STR(ft_strrchr(s, 't'), strrchr(s, 't'));
	/* 8 */ ASSERT_EQ_STR(ft_strrchr(s, 'e'), strrchr(s, 'e'));
	/* 9 */ ASSERT_EQ_STR(ft_strrchr(s, 's'), strrchr(s, 's'));
	/* 10 */ ASSERT_EQ_STR(ft_strrchr(s, 't'), strrchr(s, 't'));
	/* 11 */ ASSERT_EQ_STR(ft_strrchr(s, '-'), strrchr(s, '-'));
	/* 12 */ ASSERT_EQ_STR(ft_strrchr(s, 't'), strrchr(s, 't'));
	/* 13 */ ASSERT_EQ_STR(ft_strrchr(s, 'o'), strrchr(s, 'o'));
	/* 14 */ ASSERT_EQ_STR(ft_strrchr(s, 'k'), strrchr(s, 'k'));
	/* 15 */ ASSERT_EQ_STR(ft_strrchr(s, 'y'), strrchr(s, 'y'));
	/* 16 */ ASSERT_EQ_STR(ft_strrchr(s, 'o'), strrchr(s, 'o'));
	/* 17 */ ASSERT_EQ_STR(ft_strrchr(s, '\0'), strrchr(s, '\0'));
	/* 18 */ ASSERT_EQ_STR(ft_strrchr(s, 'l' + 256), strrchr(s, 'l' + 256));
	/* 19 */ ASSERT_EQ_STR(ft_strrchr(s, 'i' + 256), strrchr(s, 'i' + 256));
	/* 20 */ ASSERT_EQ_STR(ft_strrchr(s, 'l' - 256), strrchr(s, 'l' - 256));
	/* 21 */ ASSERT_EQ_STR(ft_strrchr(s, 'i' - 256), strrchr(s, 'i' - 256));
	/* 22 */ ASSERT_EQ_STR(ft_strrchr(s, 'z'), strrchr(s, 'z'));
	/* 23 */ ASSERT_EQ_STR(ft_strrchr(s, '~'), strrchr(s, '~'));
	return (0);
}

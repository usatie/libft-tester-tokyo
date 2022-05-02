/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 07:35:38 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:08:48 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char *s = "libft-test-tokyo";
	/* 1 */ ASSERT_EQ_STR(ft_strchr(s, 'l'), strchr(s, 'l'));
	/* 2 */ ASSERT_EQ_STR(ft_strchr(s, 'i'), strchr(s, 'i'));
	/* 3 */ ASSERT_EQ_STR(ft_strchr(s, 'b'), strchr(s, 'b'));
	/* 4 */ ASSERT_EQ_STR(ft_strchr(s, 'f'), strchr(s, 'f'));
	/* 5 */ ASSERT_EQ_STR(ft_strchr(s, 't'), strchr(s, 't'));
	/* 6 */ ASSERT_EQ_STR(ft_strchr(s, '-'), strchr(s, '-'));
	/* 7 */ ASSERT_EQ_STR(ft_strchr(s, 't'), strchr(s, 't'));
	/* 8 */ ASSERT_EQ_STR(ft_strchr(s, 'e'), strchr(s, 'e'));
	/* 9 */ ASSERT_EQ_STR(ft_strchr(s, 's'), strchr(s, 's'));
	/* 10 */ ASSERT_EQ_STR(ft_strchr(s, 't'), strchr(s, 't'));
	/* 11 */ ASSERT_EQ_STR(ft_strchr(s, '-'), strchr(s, '-'));
	/* 12 */ ASSERT_EQ_STR(ft_strchr(s, 't'), strchr(s, 't'));
	/* 13 */ ASSERT_EQ_STR(ft_strchr(s, 'o'), strchr(s, 'o'));
	/* 14 */ ASSERT_EQ_STR(ft_strchr(s, 'k'), strchr(s, 'k'));
	/* 15 */ ASSERT_EQ_STR(ft_strchr(s, 'y'), strchr(s, 'y'));
	/* 16 */ ASSERT_EQ_STR(ft_strchr(s, 'o'), strchr(s, 'o'));
	/* 17 */ ASSERT_EQ_STR(ft_strchr(s, '\0'), strchr(s, '\0'));
	/* 18 */ ASSERT_EQ_STR(ft_strchr(s, 'l' + 256), strchr(s, 'l' + 256));
	/* 19 */ ASSERT_EQ_STR(ft_strchr(s, 'i' + 256), strchr(s, 'i' + 256));
	/* 20 */ ASSERT_EQ_STR(ft_strchr(s, 'l' - 256), strchr(s, 'l' - 256));
	/* 21 */ ASSERT_EQ_STR(ft_strchr(s, 'i' - 256), strchr(s, 'i' - 256));
	/* 22 */ ASSERT_EQ_STR(ft_strchr(s, 'z'), strchr(s, 'z'));
	/* 23 */ ASSERT_EQ_STR(ft_strchr(s, '~'), strchr(s, '~'));
	return (0);
}

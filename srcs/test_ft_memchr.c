/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:41:43 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:11:03 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	// s = "libft-test-tokyo\0\0\0acdfg\0\0\0\0\0"
	char *s = calloc(30, sizeof(char));
	memcpy(s, "libft-test-tokyo", 17);
	memcpy(s + 20, "acdfg", 5);
	/* 1 */ ASSERT_EQ_PTR(ft_memchr(s, 'l', 30), memchr(s, 'l', 30));
	/* 2 */ ASSERT_EQ_PTR(ft_memchr(s, 'i', 30), memchr(s, 'i', 30));
	/* 3 */ ASSERT_EQ_PTR(ft_memchr(s, 'b', 30), memchr(s, 'b', 30));
	/* 4 */ ASSERT_EQ_PTR(ft_memchr(s, 'f', 30), memchr(s, 'f', 30));
	/* 5 */ ASSERT_EQ_PTR(ft_memchr(s, 't', 30), memchr(s, 't', 30));
	/* 6 */ ASSERT_EQ_PTR(ft_memchr(s, '-', 30), memchr(s, '-', 30));
	/* 7 */ ASSERT_EQ_PTR(ft_memchr(s, 't', 30), memchr(s, 't', 30));
	/* 8 */ ASSERT_EQ_PTR(ft_memchr(s, 'e', 30), memchr(s, 'e', 30));
	/* 9 */ ASSERT_EQ_PTR(ft_memchr(s, 's', 30), memchr(s, 's', 30));
	/* 10 */ ASSERT_EQ_PTR(ft_memchr(s, 't', 30), memchr(s, 't', 30));
	/* 11 */ ASSERT_EQ_PTR(ft_memchr(s, '-', 30), memchr(s, '-', 30));
	/* 12 */ ASSERT_EQ_PTR(ft_memchr(s, 't', 30), memchr(s, 't', 30));
	/* 13 */ ASSERT_EQ_PTR(ft_memchr(s, 'o', 30), memchr(s, 'o', 30));
	/* 14 */ ASSERT_EQ_PTR(ft_memchr(s, 'k', 30), memchr(s, 'k', 30));
	/* 15 */ ASSERT_EQ_PTR(ft_memchr(s, 'y', 30), memchr(s, 'y', 30));
	/* 16 */ ASSERT_EQ_PTR(ft_memchr(s, 'o', 30), memchr(s, 'o', 30));
	/* 17 */ ASSERT_EQ_PTR(ft_memchr(s, '\0', 30), memchr(s, '\0', 30));

	// char overflow
	/* 18 */ ASSERT_EQ_PTR(ft_memchr(s, 'l' + 256, 30), memchr(s, 'l' + 256, 30));
	/* 19 */ ASSERT_EQ_PTR(ft_memchr(s, 'i' + 256, 30), memchr(s, 'i' + 256, 30));
	/* 20 */ ASSERT_EQ_PTR(ft_memchr(s, 'l' - 256, 30), memchr(s, 'l' - 256, 30));
	/* 21 */ ASSERT_EQ_PTR(ft_memchr(s, 'i' - 256, 30), memchr(s, 'i' - 256, 30));

	// unseen characters
	/* 22 */ ASSERT_EQ_PTR(ft_memchr(s, 'z', 30), memchr(s, 'z', 30));
	/* 23 */ ASSERT_EQ_PTR(ft_memchr(s, '~', 30), memchr(s, '~', 30));

	// characters after' \0'
	/* 24 */ ASSERT_EQ_PTR(ft_memchr(s, 'a', 30), memchr(s, 'a', 30));
	/* 25 */ ASSERT_EQ_PTR(ft_memchr(s, 'c', 30), memchr(s, 'c', 30));
	/* 26 */ ASSERT_EQ_PTR(ft_memchr(s, 'd', 30), memchr(s, 'd', 30));
	/* 27 */ ASSERT_EQ_PTR(ft_memchr(s, 'f', 30), memchr(s, 'f', 30));
	/* 28 */ ASSERT_EQ_PTR(ft_memchr(s, 'g', 30), memchr(s, 'g', 30));
	return (0);
}

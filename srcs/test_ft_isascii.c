/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:54:50 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:03:42 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_isascii('a'), isascii('a'));
	/* 2 */ ASSERT_EQ_I(ft_isascii('a' - 1), isascii('a' - 1));
	/* 3 */ ASSERT_EQ_I(ft_isascii('a' + 1), isascii('a' + 1));
	/* 4 */ ASSERT_EQ_I(ft_isascii('z'), isascii('z'));
	/* 5 */ ASSERT_EQ_I(ft_isascii('z' - 1), isascii('z' - 1));
	/* 6 */ ASSERT_EQ_I(ft_isascii('z' + 1), isascii('z' + 1));
	/* 7 */ ASSERT_EQ_I(ft_isascii('A'), isascii('A'));
	/* 8 */ ASSERT_EQ_I(ft_isascii('A' - 1), isascii('A' - 1));
	/* 9 */ ASSERT_EQ_I(ft_isascii('A' + 1), isascii('A' + 1));
	/* 10 */ ASSERT_EQ_I(ft_isascii('Z'), isascii('Z'));
	/* 11 */ ASSERT_EQ_I(ft_isascii('Z' - 1), isascii('Z' - 1));
	/* 12 */ ASSERT_EQ_I(ft_isascii('Z' + 1), isascii('Z' + 1));
	/* 13 */ ASSERT_EQ_I(ft_isascii('a' + 256), isascii('a' + 256));
	/* 14 */ ASSERT_EQ_I(ft_isascii('a' - 256), isascii('a' - 256));
	/* 15 */ ASSERT_EQ_I(ft_isascii('a' + 1), isascii('a' + 1));
	/* 16 */ ASSERT_EQ_I(ft_isascii('0'), isascii('0'));
	/* 17 */ ASSERT_EQ_I(ft_isascii('0' - 1), isascii('0' - 1));
	/* 18 */ ASSERT_EQ_I(ft_isascii('0' + 1), isascii('0' + 1));
	/* 19 */ ASSERT_EQ_I(ft_isascii('9'), isascii('9'));
	/* 20 */ ASSERT_EQ_I(ft_isascii('9' - 1), isascii('9' - 1));
	/* 21 */ ASSERT_EQ_I(ft_isascii('9' + 1), isascii('9' + 1));
	/* 22 */ ASSERT_EQ_I(ft_isascii('!'), isascii('!'));
	/* 23 */ ASSERT_EQ_I(ft_isascii('{'), isascii('}'));
	/* 24 */ ASSERT_EQ_I(ft_isascii('~'), isascii('~'));
	/* 25. zero */ ASSERT_EQ_I(ft_isascii(0), isascii(0));
	/* 26. INI_MAX */ ASSERT_EQ_I(ft_isascii(INT_MAX), isascii(INT_MAX));
	/* 27. INT_MIN */ ASSERT_EQ_I(ft_isascii(INT_MIN), isascii(INT_MIN));
	/* 28 (-256~255) */ for (int i = -256; i < 256; i++) { ASSERT_EQ_I(ft_isascii(i), isascii(i)); }
	return (0);
}

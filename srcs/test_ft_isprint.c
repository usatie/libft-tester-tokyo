/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:56:06 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:03:55 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_isprint('a'), isprint('a'));
	/* 2 */ ASSERT_EQ_I(ft_isprint('a' - 1), isprint('a' - 1));
	/* 3 */ ASSERT_EQ_I(ft_isprint('a' + 1), isprint('a' + 1));
	/* 4 */ ASSERT_EQ_I(ft_isprint('z'), isprint('z'));
	/* 5 */ ASSERT_EQ_I(ft_isprint('z' - 1), isprint('z' - 1));
	/* 6 */ ASSERT_EQ_I(ft_isprint('z' + 1), isprint('z' + 1));
	/* 7 */ ASSERT_EQ_I(ft_isprint('A'), isprint('A'));
	/* 8 */ ASSERT_EQ_I(ft_isprint('A' - 1), isprint('A' - 1));
	/* 9 */ ASSERT_EQ_I(ft_isprint('A' + 1), isprint('A' + 1));
	/* 10 */ ASSERT_EQ_I(ft_isprint('Z'), isprint('Z'));
	/* 11 */ ASSERT_EQ_I(ft_isprint('Z' - 1), isprint('Z' - 1));
	/* 12 */ ASSERT_EQ_I(ft_isprint('Z' + 1), isprint('Z' + 1));
	/* 13 */ ASSERT_EQ_I(ft_isprint('a' + 256), isprint('a' + 256));
	/* 14 */ ASSERT_EQ_I(ft_isprint('a' - 256), isprint('a' - 256));
	/* 15 */ ASSERT_EQ_I(ft_isprint('a' + 1), isprint('a' + 1));
	/* 16 */ ASSERT_EQ_I(ft_isprint('0'), isprint('0'));
	/* 17 */ ASSERT_EQ_I(ft_isprint('0' - 1), isprint('0' - 1));
	/* 18 */ ASSERT_EQ_I(ft_isprint('0' + 1), isprint('0' + 1));
	/* 19 */ ASSERT_EQ_I(ft_isprint('9'), isprint('9'));
	/* 20 */ ASSERT_EQ_I(ft_isprint('9' - 1), isprint('9' - 1));
	/* 21 */ ASSERT_EQ_I(ft_isprint('9' + 1), isprint('9' + 1));
	/* 22 */ ASSERT_EQ_I(ft_isprint('!'), isprint('!'));
	/* 23 */ ASSERT_EQ_I(ft_isprint('{'), isprint('}'));
	/* 24 */ ASSERT_EQ_I(ft_isprint('~'), isprint('~'));
	/* 25. zero */ ASSERT_EQ_I(ft_isprint(0), isprint(0));
	/* 26. INI_MAX */ ASSERT_EQ_I(ft_isprint(INT_MAX), isprint(INT_MAX));
	/* 27. INT_MIN */ ASSERT_EQ_I(ft_isprint(INT_MIN), isprint(INT_MIN));
	/* 28 (-256~255) */ for (int i = -256; i < 256; i++) { ASSERT_EQ_I(ft_isprint(i), isprint(i)); }
	return (0);
}

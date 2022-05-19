/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:15 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:02:28 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_isalnum('a'), isalnum('a'));
	/* 2 */ ASSERT_EQ_I(ft_isalnum('a' - 1), isalnum('a' - 1));
	/* 3 */ ASSERT_EQ_I(ft_isalnum('a' + 1), isalnum('a' + 1));
	/* 4 */ ASSERT_EQ_I(ft_isalnum('z'), isalnum('z'));
	/* 5 */ ASSERT_EQ_I(ft_isalnum('z' - 1), isalnum('z' - 1));
	/* 6 */ ASSERT_EQ_I(ft_isalnum('z' + 1), isalnum('z' + 1));
	/* 7 */ ASSERT_EQ_I(ft_isalnum('A'), isalnum('A'));
	/* 8 */ ASSERT_EQ_I(ft_isalnum('A' - 1), isalnum('A' - 1));
	/* 9 */ ASSERT_EQ_I(ft_isalnum('A' + 1), isalnum('A' + 1));
	/* 10 */ ASSERT_EQ_I(ft_isalnum('Z'), isalnum('Z'));
	/* 11 */ ASSERT_EQ_I(ft_isalnum('Z' - 1), isalnum('Z' - 1));
	/* 12 */ ASSERT_EQ_I(ft_isalnum('Z' + 1), isalnum('Z' + 1));
	/* 13 */ ASSERT_EQ_I(ft_isalnum('a' + 256), isalnum('a' + 256));
	/* 14 */ ASSERT_EQ_I(ft_isalnum('a' - 256), isalnum('a' - 256));
	/* 15 */ ASSERT_EQ_I(ft_isalnum('a' + 1), isalnum('a' + 1));
	/* 16 */ ASSERT_EQ_I(ft_isalnum('0'), isalnum('0'));
	/* 17 */ ASSERT_EQ_I(ft_isalnum('0' - 1), isalnum('0' - 1));
	/* 18 */ ASSERT_EQ_I(ft_isalnum('0' + 1), isalnum('0' + 1));
	/* 19 */ ASSERT_EQ_I(ft_isalnum('9'), isalnum('9'));
	/* 20 */ ASSERT_EQ_I(ft_isalnum('9' - 1), isalnum('9' - 1));
	/* 21 */ ASSERT_EQ_I(ft_isalnum('9' + 1), isalnum('9' + 1));
	/* 22 */ ASSERT_EQ_I(ft_isalnum('!'), isalnum('!'));
	/* 23 */ ASSERT_EQ_I(ft_isalnum('{'), isalnum('}'));
	/* 24 */ ASSERT_EQ_I(ft_isalnum('~'), isalnum('~'));
	/* 25. zero */ ASSERT_EQ_I(ft_isalnum(0), isalnum(0));
	/* 26. INI_MAX */ ASSERT_EQ_I(ft_isalnum(INT_MAX), isalnum(INT_MAX));
	/* 27. INT_MIN */ ASSERT_EQ_I(ft_isalnum(INT_MIN), isalnum(INT_MIN));
	/* 28 (-256~255) */ for (int i = -256; i < 256; i++) { ASSERT_EQ_I(ft_isalnum(i), isalnum(i)); }
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:22:06 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:10:45 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_toupper('a'), toupper('a'));
	/* 2 */ ASSERT_EQ_I(ft_toupper('a' - 1), toupper('a' - 1));
	/* 3 */ ASSERT_EQ_I(ft_toupper('a' + 1), toupper('a' + 1));
	/* 4 */ ASSERT_EQ_I(ft_toupper('z'), toupper('z'));
	/* 5 */ ASSERT_EQ_I(ft_toupper('z' - 1), toupper('z' - 1));
	/* 6 */ ASSERT_EQ_I(ft_toupper('z' + 1), toupper('z' + 1));
	/* 7 */ ASSERT_EQ_I(ft_toupper('A'), toupper('A'));
	/* 8 */ ASSERT_EQ_I(ft_toupper('A' - 1), toupper('A' - 1));
	/* 9 */ ASSERT_EQ_I(ft_toupper('A' + 1), toupper('A' + 1));
	/* 10 */ ASSERT_EQ_I(ft_toupper('Z'), toupper('Z'));
	/* 11 */ ASSERT_EQ_I(ft_toupper('Z' - 1), toupper('Z' - 1));
	/* 12 */ ASSERT_EQ_I(ft_toupper('Z' + 1), toupper('Z' + 1));
	/* 13 */ ASSERT_EQ_I(ft_toupper('a' + 256), toupper('a' + 256));
	/* 14 */ ASSERT_EQ_I(ft_toupper('a' - 256), toupper('a' - 256));
	/* 15 */ ASSERT_EQ_I(ft_toupper('a' + 1), toupper('a' + 1));
	/* 16 */ ASSERT_EQ_I(ft_toupper('!'), toupper('!'));
	/* 17 */ ASSERT_EQ_I(ft_toupper('{'), toupper('{'));
	/* 18 */ ASSERT_EQ_I(ft_toupper('~'), toupper('~'));
	/* 19. zero */ ASSERT_EQ_I(ft_toupper(0), toupper(0));
	/* 20. INI_MAX */ ASSERT_EQ_I(ft_toupper(INT_MAX), toupper(INT_MAX));
	/* 21. INT_MIN */ ASSERT_EQ_I(ft_toupper(INT_MIN), toupper(INT_MIN));
	/* 22 (-256~255) */ for (int i = -256; i < 256; i++) { ASSERT_EQ_I(ft_toupper(i), toupper(i)); }
	return (0);
}

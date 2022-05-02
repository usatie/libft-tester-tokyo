/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:35:50 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:02:33 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_isalpha('a'), isalpha('b'));
	/* 2 */ ASSERT_EQ_I(ft_isalpha('a' - 1), isalpha('a' - 1));
	/* 3 */ ASSERT_EQ_I(ft_isalpha('a' + 1), isalpha('a' + 1));
	/* 4 */ ASSERT_EQ_I(ft_isalpha('z'), isalpha('z'));
	/* 5 */ ASSERT_EQ_I(ft_isalpha('z' - 1), isalpha('z' - 1));
	/* 6 */ ASSERT_EQ_I(ft_isalpha('z' + 1), isalpha('z' + 1));
	/* 7 */ ASSERT_EQ_I(ft_isalpha('A'), isalpha('A'));
	/* 8 */ ASSERT_EQ_I(ft_isalpha('A' - 1), isalpha('A' - 1));
	/* 9 */ ASSERT_EQ_I(ft_isalpha('A' + 1), isalpha('A' + 1));
	/* 10 */ ASSERT_EQ_I(ft_isalpha('Z'), isalpha('Z'));
	/* 11 */ ASSERT_EQ_I(ft_isalpha('Z' - 1), isalpha('Z' - 1));
	/* 12 */ ASSERT_EQ_I(ft_isalpha('Z' + 1), isalpha('Z' + 1));
	/* 13 */ ASSERT_EQ_I(ft_isalpha('a' + 256), isalpha('a' + 256));
	/* 14 */ ASSERT_EQ_I(ft_isalpha('a' - 256), isalpha('a' - 256));
	/* 15 */ ASSERT_EQ_I(ft_isalpha('a' + 1), isalpha('a' + 1));
	/* 16 */ ASSERT_EQ_I(ft_isalpha('!'), isalpha('!'));
	/* 17 */ ASSERT_EQ_I(ft_isalpha('{'), isalpha('}'));
	/* 18 */ ASSERT_EQ_I(ft_isalpha('~'), isalpha('~'));
	/* 19. zero */ ASSERT_EQ_I(ft_isalpha(0), isalpha(0));
	/* 20. INI_MAX */ ASSERT_EQ_I(ft_isalpha(INT_MAX), isalpha(INT_MAX));
	/* 21. INT_MIN */ ASSERT_EQ_I(ft_isalpha(INT_MIN), isalpha(INT_MIN));
	/* 22 (-256~255) */ for (int i = -256; i < 256; i++) { ASSERT_EQ_I(ft_isalpha(i), isalpha(i)); }
	return (0);
}

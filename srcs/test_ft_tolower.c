/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:28:39 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:10:38 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_tolower('a'), tolower('a'));
	/* 2 */ ASSERT_EQ_I(ft_tolower('a' - 1), tolower('a' - 1));
	/* 3 */ ASSERT_EQ_I(ft_tolower('a' + 1), tolower('a' + 1));
	/* 4 */ ASSERT_EQ_I(ft_tolower('z'), tolower('z'));
	/* 5 */ ASSERT_EQ_I(ft_tolower('z' - 1), tolower('z' - 1));
	/* 6 */ ASSERT_EQ_I(ft_tolower('z' + 1), tolower('z' + 1));
	/* 7 */ ASSERT_EQ_I(ft_tolower('A'), tolower('A'));
	/* 8 */ ASSERT_EQ_I(ft_tolower('A' - 1), tolower('A' - 1));
	/* 9 */ ASSERT_EQ_I(ft_tolower('A' + 1), tolower('A' + 1));
	/* 10 */ ASSERT_EQ_I(ft_tolower('Z'), tolower('Z'));
	/* 11 */ ASSERT_EQ_I(ft_tolower('Z' - 1), tolower('Z' - 1));
	/* 12 */ ASSERT_EQ_I(ft_tolower('Z' + 1), tolower('Z' + 1));
	/* 13 */ ASSERT_EQ_I(ft_tolower('a' + 256), tolower('a' + 256));
	/* 14 */ ASSERT_EQ_I(ft_tolower('a' - 256), tolower('a' - 256));
	/* 15 */ ASSERT_EQ_I(ft_tolower('a' + 1), tolower('a' + 1));
	/* 16 */ ASSERT_EQ_I(ft_tolower('!'), tolower('!'));
	/* 17 */ ASSERT_EQ_I(ft_tolower('{'), tolower('{'));
	/* 18 */ ASSERT_EQ_I(ft_tolower('~'), tolower('~'));
	/* 19. zero */ ASSERT_EQ_I(ft_tolower(0), tolower(0));
	/* 20. INI_MAX */ ASSERT_EQ_I(ft_tolower(INT_MAX), tolower(INT_MAX));
	/* 21. INT_MIN */ ASSERT_EQ_I(ft_tolower(INT_MIN), tolower(INT_MIN));
	/* 22 (-256~255) */ for (int i = -256; i < 256; i++) { ASSERT_EQ_I(ft_tolower(i), tolower(i)); }
	return (0);
}

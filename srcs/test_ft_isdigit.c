/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:51:05 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:03:48 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_isdigit('0'), isdigit('0'));
	/* 2 */ ASSERT_EQ_I(ft_isdigit('0' - 1), isdigit('0' - 1));
	/* 3 */ ASSERT_EQ_I(ft_isdigit('0' + 1), isdigit('0' + 1));
	/* 4 */ ASSERT_EQ_I(ft_isdigit('9'), isdigit('9'));
	/* 5 */ ASSERT_EQ_I(ft_isdigit('9' - 1), isdigit('9' - 1));
	/* 6 */ ASSERT_EQ_I(ft_isdigit('9' + 1), isdigit('9' + 1));
	/* 7 */ ASSERT_EQ_I(ft_isdigit('!'), isdigit('!'));
	/* 8 */ ASSERT_EQ_I(ft_isdigit('{'), isdigit('}'));
	/* 9 */ ASSERT_EQ_I(ft_isdigit('~'), isdigit('~'));
	/* 10. zero */ ASSERT_EQ_I(ft_isdigit(0), isdigit(0));
	/* 11. INI_MAX */ ASSERT_EQ_I(ft_isdigit(INT_MAX), isdigit(INT_MAX));
	/* 12. INT_MIN */ ASSERT_EQ_I(ft_isdigit(INT_MIN), isdigit(INT_MIN));
	/* 13 (-256~255) */ for (int i = -256; i < 256; i++) { ASSERT_EQ_I(ft_isdigit(i), isdigit(i)); }
	return (0);
}

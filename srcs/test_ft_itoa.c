/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:32:54 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:04:04 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_STR(ft_itoa(0), "0");
	/* 2 */ ASSERT_EQ_STR(ft_itoa(-0), "0");
	/* 3 */ ASSERT_EQ_STR(ft_itoa(+0), "0");
	/* 4 */ ASSERT_EQ_STR(ft_itoa(1),"1");
	/* 5 */ ASSERT_EQ_STR(ft_itoa(-1),"-1");
	/* 6 */ ASSERT_EQ_STR(ft_itoa(+1),"1");
	/* 7 */ ASSERT_EQ_STR(ft_itoa(7),"7");
	/* 8 */ ASSERT_EQ_STR(ft_itoa(-7),"-7");
	/* 9 */ ASSERT_EQ_STR(ft_itoa(+7),"7");
	/* 10 */ ASSERT_EQ_STR(ft_itoa(42), "42");
	/* 11 */ ASSERT_EQ_STR(ft_itoa(-42), "-42");
	/* 12 */ ASSERT_EQ_STR(ft_itoa(+42), "42");
	/* 13. INT_MAX */ ASSERT_EQ_STR(ft_itoa(2147483647),"2147483647");
	/* 14. INT_MIN */ ASSERT_EQ_STR(ft_itoa(-2147483648),"-2147483648");
	/* 15. INT_MAX - 1 */ ASSERT_EQ_STR(ft_itoa(2147483646), "2147483646");
	/* 16. INT_MIN + 1 */ ASSERT_EQ_STR(ft_itoa(-2147483647), "-2147483647");
	
	return (0);
}

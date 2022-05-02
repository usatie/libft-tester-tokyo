/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_aoti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:05:54 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 09:48:50 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_I(ft_atoi(""), atoi(""));
	/* 2 */ ASSERT_EQ_I(ft_atoi("-"), atoi("-"));
	/* 3 */ ASSERT_EQ_I(ft_atoi("+"), atoi("+"));
	/* 4 */ ASSERT_EQ_I(ft_atoi("0"), atoi("0"));
	/* 5 */ ASSERT_EQ_I(ft_atoi("-0"), atoi("-0"));
	/* 6 */ ASSERT_EQ_I(ft_atoi("+0"), atoi("+0"));
	/* 7 */ ASSERT_EQ_I(ft_atoi("1"), atoi("1"));
	/* 8 */ ASSERT_EQ_I(ft_atoi("-1"), atoi("-1"));
	/* 9 */ ASSERT_EQ_I(ft_atoi("+1"), atoi("+1"));
	/* 10 */ ASSERT_EQ_I(ft_atoi("7"), atoi("7"));
	/* 11 */ ASSERT_EQ_I(ft_atoi("-7"), atoi("-7"));
	/* 12 */ ASSERT_EQ_I(ft_atoi("+7"), atoi("+7"));
	/* 13 */ ASSERT_EQ_I(ft_atoi("42"), atoi("42"));
	/* 14 */ ASSERT_EQ_I(ft_atoi("-42"), atoi("-42"));
	/* 15 */ ASSERT_EQ_I(ft_atoi("a"), atoi("a"));
	/* 16 */ ASSERT_EQ_I(ft_atoi("!"), atoi("!"));
	/* 17. INT_MAX */ ASSERT_EQ_I(ft_atoi("2147483647"), atoi("2147483647"));
	/* 18. INT_MIN */ ASSERT_EQ_I(ft_atoi("-2147483648"), atoi("-2147483648"));
	/* 19. UINT_MAX */ ASSERT_EQ_I(ft_atoi("4294967295"), atoi("4294967295"));
	/* 20. LONG_MAX */ ASSERT_EQ_I(ft_atoi("9223372036854775807"), atoi("9223372036854775807"));
	/* 21. LONG_MIN */ ASSERT_EQ_I(ft_atoi("-9223372036854775808"), atoi("-9223372036854775808"));
	/* 22. ULONG_MAX */ ASSERT_EQ_I(ft_atoi("18446744073709551615"), atoi("18446744073709551615"));
	/* 23. SIZE_MAX */ ASSERT_EQ_I(ft_atoi("18446744073709551615"), atoi("18446744073709551615"));

	/* 24. INT_MAX + 1 */ ASSERT_EQ_I(atoi("2147483648"), ft_atoi("2147483648"));
	/* 25. INT_MIN - 1 */ ASSERT_EQ_I(atoi("-2147483649"), ft_atoi("-2147483649"));
	/* 26. UINT_MAX + 1 */ ASSERT_EQ_I(atoi("4294967296"), ft_atoi("4294967296"));
	/* 27. LONG_MAX + 1 */ ASSERT_EQ_I(atoi("9223372036854775808"), ft_atoi("9223372036854775808"));
	/* 28. LONG_MIN - 1 */ ASSERT_EQ_I(atoi("-9223372036854775809"), ft_atoi("-9223372036854775809"));
	/* 29. ULONG_MAX + 1 */ ASSERT_EQ_I(atoi("18446744073709551616"), ft_atoi("18446744073709551616"));
	/* 30. SIZE_MAX + 1 */ ASSERT_EQ_I(atoi("18446744073709551616"), ft_atoi("18446744073709551616"));

	/* 31. INT_MAX - 1 */ ASSERT_EQ_I(atoi("2147483646"), ft_atoi("2147483646"));
	/* 32. INT_MIN + 1 */ ASSERT_EQ_I(atoi("-2147483647"), ft_atoi("-2147483647"));
	/* 33. UINT_MAX - 1 */ ASSERT_EQ_I(atoi("4294967294"), ft_atoi("4294967294"));
	/* 34. LONG_MAX - 1 */ ASSERT_EQ_I(atoi("9223372036854775806"), ft_atoi("9223372036854775806"));
	/* 35. LONG_MIN + 1 */ ASSERT_EQ_I(atoi("-9223372036854775807"), ft_atoi("-9223372036854775807"));
	/* 36. ULONG_MAX - 1 */ ASSERT_EQ_I(atoi("18446744073709551614"), ft_atoi("18446744073709551614"));
	/* 37. SIZE_MAX - 1 */ ASSERT_EQ_I(atoi("18446744073709551614"), ft_atoi("18446744073709551614"));
	
	/* 38. Many zeros 1*/ ASSERT_EQ_I(atoi("000000000000000000008"), ft_atoi("000000000000000000008"));
	/* 39. Many zeros 2*/ ASSERT_EQ_I(atoi("-000000000000000000008"), ft_atoi("-000000000000000000008"));
	/* 40. Many zeros 3*/ ASSERT_EQ_I(atoi("+000000000000000000008"), ft_atoi("+000000000000000000008"));
	return (0);
}

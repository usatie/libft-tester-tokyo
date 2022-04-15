/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_aoti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:05:54 by susami            #+#    #+#             */
/*   Updated: 2022/04/15 11:42:45 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "libassert.h"

int	main(void)
{
	ASSERT_EQ_I(atoi(""), ft_atoi(""));
	ASSERT_EQ_I(atoi("-"), ft_atoi("-"));
	ASSERT_EQ_I(atoi("+"), ft_atoi("+"));
	ASSERT_EQ_I(atoi("0"), ft_atoi("0"));
	ASSERT_EQ_I(atoi("-0"), ft_atoi("-0"));
	ASSERT_EQ_I(atoi("+0"), ft_atoi("+0"));
	ASSERT_EQ_I(atoi("1"), ft_atoi("1"));
	ASSERT_EQ_I(atoi("-1"), ft_atoi("-1"));
	ASSERT_EQ_I(atoi("+1"), ft_atoi("+1"));
	ASSERT_EQ_I(atoi("7"), ft_atoi("7"));
	ASSERT_EQ_I(atoi("-7"), ft_atoi("-7"));
	ASSERT_EQ_I(atoi("+7"), ft_atoi("+7"));
	ASSERT_EQ_I(atoi("42"), ft_atoi("42"));
	ASSERT_EQ_I(atoi("-42"), ft_atoi("-42"));
	ASSERT_EQ_I(atoi("a"), ft_atoi("a"));
	ASSERT_EQ_I(atoi("!"), ft_atoi("!"));
	/* INT_MAX */ ASSERT_EQ_I(atoi("2147483647"), ft_atoi("2147483647"));
	/* INT_MIN */ ASSERT_EQ_I(atoi("-2147483648"), ft_atoi("-2147483648"));
	/* UINT_MAX */ ASSERT_EQ_I(atoi("4294967295"), ft_atoi("4294967295"));
	/* LONG_MAX */ ASSERT_EQ_I(atoi("9223372036854775807"), ft_atoi("9223372036854775807"));
	/* LONG_MIN */ ASSERT_EQ_I(atoi("-9223372036854775808"), ft_atoi("-9223372036854775808"));
	/* ULONG_MAX */ ASSERT_EQ_I(atoi("18446744073709551615"), ft_atoi("18446744073709551615"));
	/* SIZE_MAX */ ASSERT_EQ_I(atoi("18446744073709551615"), ft_atoi("18446744073709551615"));

	/* INT_MAX + 1 */ ASSERT_EQ_I(atoi("2147483648"), ft_atoi("2147483648"));
	/* INT_MIN - 1 */ ASSERT_EQ_I(atoi("-2147483649"), ft_atoi("-2147483649"));
	/* UINT_MAX + 1 */ ASSERT_EQ_I(atoi("4294967296"), ft_atoi("4294967296"));
	/* LONG_MAX + 1 */ ASSERT_EQ_I(atoi("9223372036854775808"), ft_atoi("9223372036854775808"));
	/* LONG_MIN - 1 */ ASSERT_EQ_I(atoi("-9223372036854775809"), ft_atoi("-9223372036854775809"));
	/* ULONG_MAX + 1 */ ASSERT_EQ_I(atoi("18446744073709551616"), ft_atoi("18446744073709551616"));
	/* SIZE_MAX + 1 */ ASSERT_EQ_I(atoi("18446744073709551616"), ft_atoi("18446744073709551616"));

	/* INT_MAX - 1 */ ASSERT_EQ_I(atoi("2147483646"), ft_atoi("2147483646"));
	/* INT_MIN + 1 */ ASSERT_EQ_I(atoi("-2147483647"), ft_atoi("-2147483647"));
	/* UINT_MAX - 1 */ ASSERT_EQ_I(atoi("4294967294"), ft_atoi("4294967294"));
	/* LONG_MAX - 1 */ ASSERT_EQ_I(atoi("9223372036854775806"), ft_atoi("9223372036854775806"));
	/* LONG_MIN + 1 */ ASSERT_EQ_I(atoi("-9223372036854775807"), ft_atoi("-9223372036854775807"));
	/* ULONG_MAX - 1 */ ASSERT_EQ_I(atoi("18446744073709551614"), ft_atoi("18446744073709551614"));
	/* SIZE_MAX - 1 */ ASSERT_EQ_I(atoi("18446744073709551614"), ft_atoi("18446744073709551614"));
	return (0);
}

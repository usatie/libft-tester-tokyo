/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:10:25 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:02:21 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	check_calloc(size_t cnt, size_t size)
{
	void	*actual = ft_calloc(cnt, size);
	void	*expected = calloc(cnt, size);
	ASSERT_EQ_MALLOC_SIZE(actual, expected);
	ASSERT_EQ_MEM(actual, expected, cnt * size);
}

int	main(void)
{
	/* 1,2 */ check_calloc(0, 0);
	/* 3,4 */ check_calloc(1, 0);
	/* 5,6 */ check_calloc(0, 1);
	/* 7,8 */ check_calloc(1, 1);
	/* 9,10 */ check_calloc(42, 1);
	/* 11,12 */ check_calloc(1, 42);
	/* 13,14 */ check_calloc(42, 42);
	/* 15,16 overflow */ check_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10);
	/* 17,18 too big 1*/ check_calloc(LONG_MAX, 1);
	/* 19,20 too big 2*/ check_calloc(ULONG_MAX, 1);
	/* 21,22 too big 3*/ check_calloc(SIZE_MAX, 1);
	// /* 23,24 very big 1*/ check_calloc(INT_MAX, 1);
	// /* 25,26 very big 2*/ check_calloc(UINT_MAX, 1);
	return (0);
}

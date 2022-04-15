/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:10:25 by susami            #+#    #+#             */
/*   Updated: 2022/04/15 14:10:02 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "libassert.h"
#include <malloc/malloc.h>

void	check_calloc(size_t cnt, size_t size)
{
	void	*actual = ft_calloc(cnt, size);
	void	*expected = calloc(cnt, size);
	ASSERT_EQ_MEM(actual, expected, cnt * size);
}

int	main(void)
{
	/* 1 */ check_calloc(0, 0);
	/* 2 */ check_calloc(1, 0);
	/* 3 */ check_calloc(0, 1);
	/* 4 */ check_calloc(1, 1);
	/* 5 */ check_calloc(42, 1);
	/* 6 */ check_calloc(1, 42);
	/* 7 */ check_calloc(42, 42);
	/* 8 */ check_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10);
	/* 9 */ check_calloc(INT_MAX, 1);
	/* 10 */ check_calloc(UINT_MAX, 1);
	/* 11 */ check_calloc(LONG_MAX, 1);
	/* 12 */ check_calloc(ULONG_MAX, 1);
	/* 13 */ check_calloc(SIZE_MAX, 1);
	return (0);
}

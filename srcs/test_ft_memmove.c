/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:09:36 by susami            #+#    #+#             */
/*   Updated: 2022/04/19 00:29:07 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "libassert.h"

void	check_memmove(void *dst, void *src, size_t size)
{
	void	*expected = malloc(size);
	memmove(expected, src, size);
	ft_memmove(dst, src, size);
	ASSERT_EQ_MEM(dst, expected, size);
	if (expected)
		free(expected);
}

int	main(void)
{
	char *src = malloc(100);
	for (int i = 0; i < 100; i++)
		src[i] = i;
	char *dst = malloc(100);
	/* 1 */ check_memmove(dst, src, 0);
	/* 2 */ check_memmove(dst, src, 10);
	/* 2 */ check_memmove(dst, src, 100);
	/* 3 forward overlap */ check_memmove(dst + 42, dst, 50);
	/* 4 backward overlap*/ check_memmove(dst, dst + 21, 50);
	return (0);
}

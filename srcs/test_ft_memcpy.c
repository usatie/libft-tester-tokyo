/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:04:04 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:07:14 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	check_memcpy(void *dst, void *src, size_t size)
{
	void	*expected = malloc(size);
	memcpy(expected, src, size);
	ft_memcpy(dst, src, size);
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
	/* 1 */ check_memcpy(dst, src, 0);
	/* 2 */ check_memcpy(dst, src, 10);
	/* 2 */ check_memcpy(dst, src, 100);
	// undefined: /* 3 forward overlap */ check_memcpy(dst + 5, dst, 10);
	// undefined: /* 4 backward overlap*/ check_memcpy(dst, dst + 3, 10);
	return (0);
}

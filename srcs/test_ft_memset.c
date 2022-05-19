/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:11:14 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:07:30 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	check_memset(char *s1, char *s2, int val, size_t size)
{
	void	*actual = ft_memset(s1, val, size);
	void	*expected = memset(s2, val, size);
	ASSERT_EQ_MEM(actual, expected, size);
}

int	main(void)
{
	char	*s1, *s2;
	
	/* 1 */ s1 = calloc(100, 100); s2 = calloc(100, 100); check_memset(s1, s2, 0, 0); free(s1); free(s2);
	/* 2 */ s1 = calloc(100, 100); s2 = calloc(100, 100); check_memset(s1, s2, 1, 0); free(s1); free(s2);
	/* 3 */ s1 = calloc(100, 100); s2 = calloc(100, 100); check_memset(s1, s2, 0, 1); free(s1); free(s2);
	/* 4 */ s1 = calloc(100, 100); s2 = calloc(100, 100); check_memset(s1, s2, 42, 0); free(s1); free(s2);
	/* 5 */ s1 = calloc(100, 100); s2 = calloc(100, 100); check_memset(s1, s2, 0, 42); free(s1); free(s2);
	/* 6 */ s1 = calloc(100, 100); s2 = calloc(100, 100); check_memset(s1, s2, 42, 42); free(s1); free(s2);
	/* 7 */ s1 = calloc(100, 100); s2 = calloc(100, 100); check_memset(s1, s2, INT_MAX, 42); free(s1); free(s2);
	/* 8 */ s1 = calloc(100, 100); s2 = calloc(100, 100); check_memset(s1, s2, INT_MIN, 42); free(s1); free(s2);
	/* 10 */ check_memset(NULL, NULL, 0, 0);
	// Very slow
	// /* 9 */ s1 = calloc(INT_MAX, 1); s2 = calloc(INT_MAX, 1); check_memset(s1, s2, 42, INT_MAX); free(s1); free(s2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:40:45 by susami            #+#    #+#             */
/*   Updated: 2022/04/18 10:16:25 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "libassert.h"
#include <malloc/malloc.h>

void	check_bzero(char *s1, char *s2, size_t size)
{
	memset(s1, 'A', size);
	memset(s2, 'B', size);
	ft_bzero(s1, size);
	bzero(s2, size);
	void	*actual = s1;
	void	*expected = s2;
	ASSERT_EQ_MEM(actual, expected, size);
}

int	main(void)
{
	char	*s1, *s2;
	
	/* 1 */ s1 = malloc(100); s2 = malloc(100); check_bzero(s1, s2, 0); free(s1); free(s2);
	/* 2 */ s1 = malloc(100); s2 = malloc(100); check_bzero(s1, s2, 1); free(s1); free(s2);
	/* 3 */ s1 = malloc(100); s2 = malloc(100); check_bzero(s1, s2, 42); free(s1); free(s2);
	/* 4 */ s1 = malloc(100); s2 = malloc(100); check_bzero(s1, s2, 100); free(s1); free(s2);
	/* 5 */ ASSERT_EQ_MEM(ft_bzero(NULL, 0), bzero(NULL, 0), 0);
	// Segmentatino Fault
	// /* 5 */ ASSERT_EQ_MEM(ft_bzero(NULL, 1), bzero(NULL, 1), 1);

	// very slow
	// /* 5 */ s1 = malloc(INT_MAX); s2 = malloc(INT_MAX); check_bzero(s1, s2, INT_MAX); free(s1); free(s2);
	return (0);
}

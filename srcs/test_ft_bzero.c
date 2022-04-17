/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:40:45 by susami            #+#    #+#             */
/*   Updated: 2022/04/15 18:02:20 by susami           ###   ########.fr       */
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
	void	*actual = ft_bzero(s1, size);
	void	*expected = bzero(s2, size);
	ASSERT_EQ_MEM(actual, expected, size);
}

int	main(void)
{
	char	*s1, *s2;
	
	/* 1 */ s1 = malloc(100); s2 = malloc(100); check_bzero(s1, s2, 0); free(s1); free(s2);
	/* 2 */ s1 = malloc(100); s2 = malloc(100); check_bzero(s1, s2, 1); free(s1); free(s2);
	/* 3 */ s1 = malloc(100); s2 = malloc(100); check_bzero(s1, s2, 42); free(s1); free(s2);
	/* 4 */ s1 = malloc(100); s2 = malloc(100); check_bzero(s1, s2, 100); free(s1); free(s2);
	/* 5 */ s1 = malloc(INT_MAX); s2 = malloc(INT_MAX); check_bzero(s1, s2, INT_MAX); free(s1); free(s2);
	return (0);
}

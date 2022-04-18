/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:25:42 by susami            #+#    #+#             */
/*   Updated: 2022/04/18 10:31:36 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "libassert.h"
#include <malloc/malloc.h>

void	check_strdup(char *str)
{
	void	*actual = ft_strdup(str);
	void	*expected = strdup(str);
	ASSERT_EQ_MALLOC_SIZE(actual, expected);
	ASSERT_EQ_STR(actual, expected);
}

int	main(void)
{
	/* 1,2 */ check_strdup("");
	/* 3,4 */ check_strdup("hello");
	/* 5,6 */ check_strdup("hello world");
	char *str = malloc(1000);
	str = memset(str, 'A', 999);
	str[999] = '\0';
	/* 7,8 */ check_strdup(str);

	// Segmentation Fault
	// /* 1,2 */ check_strdup(NULL);
	return (0);
}

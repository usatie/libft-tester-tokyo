/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:34:25 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:08:39 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	assert_str_array(char **actual, char **expected)
{
	// Check the non NULL elements
	while (*expected)
		ASSERT_EQ_STR(*actual++, *expected++);
	// Check the last element to be NULL
	ASSERT_EQ_PTR(*actual, *expected);
}

int	main(void)
{
	char *expected[] = {"hello","world","42","tokyo", NULL};
	/* 1 ~ 5 */ assert_str_array(ft_split("hello,world,42,tokyo", ','), expected);
	/* 6 ~ 10 */ assert_str_array(ft_split("hello world 42 tokyo", ' '), expected);
	/* 11 ~ 15 */ assert_str_array(ft_split(",,,hello,,,world,,,42,,,tokyo,,,,", ','), expected);

	char *expected2[] = {"hello,world,42,tokyo", NULL};
	/* 16 ~ 17 */ assert_str_array(ft_split("hello,world,42,tokyo", ' '), expected2);
	/* 18 ~ 19 */ assert_str_array(ft_split("hello,world,42,tokyo", '{'), expected2);

	char *expected3[] = {NULL};
	/* 20 */ assert_str_array(ft_split("", ','), expected3);

	// Segmentation Fault
	// /* 21 */ assert_str_array(ft_split(NULL, ','), expected3);
	
}

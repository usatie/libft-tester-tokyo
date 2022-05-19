/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 09:06:34 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:10:08 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char *str = "libft-test-tokyo";
	int	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		ASSERT_EQ_PTR(ft_strnstr(str, "", i), strnstr(str, "", i));
		ASSERT_EQ_PTR(ft_strnstr(str, "libft-test-tokyo", i), strnstr(str, "libft-test-tokyo", i));
		ASSERT_EQ_PTR(ft_strnstr(str, "libft", i), strnstr(str, "libft", i));
		ASSERT_EQ_PTR(ft_strnstr(str, "test", i), strnstr(str, "test", i));
		ASSERT_EQ_PTR(ft_strnstr(str, "tokyo", i), strnstr(str, "tokyo", i));
		ASSERT_EQ_PTR(ft_strnstr(str, "libft~", i), strnstr(str, "libft~", i));
		ASSERT_EQ_PTR(ft_strnstr(str, "z", i), strnstr(str, "z", i));
	}
    /* 113 */ ASSERT_EQ_PTR(ft_strnstr("", "hello", 5), strnstr("", "hello", 5));
    /* 114 */ ASSERT_EQ_PTR(ft_strnstr("", "", 0), strnstr("", "", 0));
    /* 115 */ ASSERT_EQ_PTR(ft_strnstr(NULL, "1", 0), strnstr(NULL, "1", 0));
    // Segmentation Fault
    // /* 116 */ ASSERT_EQ_PTR(ft_strnstr(NULL, "fake", 3), strnstr(NULL, "fake", 3));
    // /* 116 */ ASSERT_EQ_PTR(ft_strnstr(NULL, "1", 1), ft_strnstr(NULL, "1", 1));
}

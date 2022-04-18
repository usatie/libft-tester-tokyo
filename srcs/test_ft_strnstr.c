/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 09:06:34 by susami            #+#    #+#             */
/*   Updated: 2022/04/18 09:14:41 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"
#include "libassert.h"

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
}

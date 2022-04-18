/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:20:37 by susami            #+#    #+#             */
/*   Updated: 2022/04/19 00:30:23 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "libassert.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_STR(ft_strjoin("hello", "world"), "helloworld");
	/* 2 */ ASSERT_EQ_STR(ft_strjoin("", "world"), "world");
	/* 3 */ ASSERT_EQ_STR(ft_strjoin("hello", ""), "hello");
	/* 4 */ ASSERT_EQ_STR(ft_strjoin("", ""), "");
}

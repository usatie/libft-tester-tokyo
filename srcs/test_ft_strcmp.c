/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:34:13 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 13:15:13 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char	*s1, *s2;
	s1 = ""; s2 = "";
	/* 1 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "ABC"; s2 = "ABCDEFG";
	/* 2 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "ABC"; s2 = "Z";
	/* 3 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "ABC"; s2 = "A0";
	/* 4 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "ABC"; s2 = "é";
	/* 5 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "ABC"; s2 = "A";
	/* 6 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "abcde"; s2 = "abcdf";
	/* 7 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "abcde"; s2 = "abcdd";
	/* 8 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "abcde"; s2 = "abcd1";
	/* 9 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "abcde"; s2 = "abcd";
	/* 10 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "abcd"; s2 = "abcde";
	/* 11 */ ASSERT_EQ_I(ft_strcmp(s1, s2), strcmp(s1, s2));
}

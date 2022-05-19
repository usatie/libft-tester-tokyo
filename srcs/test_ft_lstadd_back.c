/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:05:23 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:04:13 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
    t_list  *lst = NULL;
    t_list  *elem1 = calloc(sizeof(t_list), 1);
    t_list  *elem2 = calloc(sizeof(t_list), 1);
    t_list  *elem3 = calloc(sizeof(t_list), 1);
    t_list  *elem4 = calloc(sizeof(t_list), 1);
    t_list  *elem5 = calloc(sizeof(t_list), 1);
    char    *s1 = "hello";
    char    *s2 = "world";
    char    *s3 = "42!";
    int     val4 = 42;
    int     val5 = -42;
    elem1->content = s1;
    elem2->content = s2;
    elem3->content = s3;
    elem4->content = &val4;
    elem5->content = &val5;

    
    /* Add back #1 */
    ft_lstadd_back(&lst, elem1);
    /* 1 */ ASSERT_EQ_PTR(lst, elem1);
    /* 2 */ ASSERT_EQ_PTR(lst->content, s1);
    /* 3 */ ASSERT_EQ_PTR(lst->next, NULL);

    /* Add back #2 */
    ft_lstadd_back(&lst, elem2);
    /* 4 */ ASSERT_EQ_PTR(lst, elem1);
    /* 5 */ ASSERT_EQ_PTR(lst->content, s1);
    /* 6 */ ASSERT_EQ_PTR(lst->next, elem2);
    /* 7 */ ASSERT_EQ_PTR(lst->next->content, s2);
    /* 8 */ ASSERT_EQ_PTR(lst->next->next, NULL);

    /* Add back #3 */
    ft_lstadd_back(&lst, elem3);
    /* 9 */ ASSERT_EQ_PTR(lst, elem1);
    /* 10 */ ASSERT_EQ_PTR(lst->content, s1);
    /* 11 */ ASSERT_EQ_PTR(lst->next, elem2);
    /* 12 */ ASSERT_EQ_PTR(lst->next->content, s2);
    /* 13 */ ASSERT_EQ_PTR(lst->next->next, elem3);
    /* 14 */ ASSERT_EQ_PTR(lst->next->next->content, s3);
    /* 15 */ ASSERT_EQ_PTR(lst->next->next->next, NULL);

    /* Add back #4 */
    ft_lstadd_back(&lst, elem4);
    /* 16 */ ASSERT_EQ_PTR(lst, elem1);
    /* 17 */ ASSERT_EQ_PTR(lst->content, s1);
    /* 18 */ ASSERT_EQ_PTR(lst->next, elem2);
    /* 19 */ ASSERT_EQ_PTR(lst->next->content, s2);
    /* 20 */ ASSERT_EQ_PTR(lst->next->next, elem3);
    /* 21 */ ASSERT_EQ_PTR(lst->next->next->content, s3);
    /* 22 */ ASSERT_EQ_PTR(lst->next->next->next, elem4);
    /* 23 */ ASSERT_EQ_PTR(lst->next->next->next->content, &val4);
    /* 24 */ ASSERT_EQ_PTR(lst->next->next->next->next, NULL);

    /* Add back #5 */
    ft_lstadd_back(&lst, elem5);
    /* 25 */ ASSERT_EQ_PTR(lst, elem1);
    /* 26 */ ASSERT_EQ_PTR(lst->content, s1);
    /* 27 */ ASSERT_EQ_PTR(lst->next, elem2);
    /* 28 */ ASSERT_EQ_PTR(lst->next->content, s2);
    /* 29 */ ASSERT_EQ_PTR(lst->next->next, elem3);
    /* 30 */ ASSERT_EQ_PTR(lst->next->next->content, s3);
    /* 31 */ ASSERT_EQ_PTR(lst->next->next->next, elem4);
    /* 32 */ ASSERT_EQ_PTR(lst->next->next->next->content, &val4);
    /* 33 */ ASSERT_EQ_PTR(lst->next->next->next->next, elem5);
    /* 34 */ ASSERT_EQ_PTR(lst->next->next->next->next->content, &val5);
    /* 35 */ ASSERT_EQ_PTR(lst->next->next->next->next->next, NULL);
	return (0);
}

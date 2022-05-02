/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:47:15 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:04:58 by susami           ###   ########.fr       */
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

    
    /* Add front #1 */
    ft_lstadd_front(&lst, elem1);
    /* 1 */ ASSERT_EQ_PTR(lst, elem1);
    /* 2 */ ASSERT_EQ_PTR(lst->content, s1);
    /* 3 */ ASSERT_EQ_PTR(lst->next, NULL);

    /* Add front #2 */
    ft_lstadd_front(&lst, elem2);
    /* 4 */ ASSERT_EQ_PTR(lst, elem2);
    /* 5 */ ASSERT_EQ_PTR(lst->content, s2);
    /* 6 */ ASSERT_EQ_PTR(lst->next, elem1);
    /* 7 */ ASSERT_EQ_PTR(lst->next->content, s1);
    /* 8 */ ASSERT_EQ_PTR(lst->next->next, NULL);

    /* Add front #3 */
    ft_lstadd_front(&lst, elem3);
    /* 9 */ ASSERT_EQ_PTR(lst, elem3);
    /* 10 */ ASSERT_EQ_PTR(lst->content, s3);
    /* 11 */ ASSERT_EQ_PTR(lst->next, elem2);
    /* 12 */ ASSERT_EQ_PTR(lst->next->content, s2);
    /* 13 */ ASSERT_EQ_PTR(lst->next->next, elem1);
    /* 14 */ ASSERT_EQ_PTR(lst->next->next->content, s1);
    /* 15 */ ASSERT_EQ_PTR(lst->next->next->next, NULL);

    /* Add front #4 */
    ft_lstadd_front(&lst, elem4);
    /* 16 */ ASSERT_EQ_PTR(lst, elem4);
    /* 17 */ ASSERT_EQ_PTR(lst->content, &val4);
    /* 18 */ ASSERT_EQ_PTR(lst->next, elem3);
    /* 19 */ ASSERT_EQ_PTR(lst->next->content, s3);
    /* 20 */ ASSERT_EQ_PTR(lst->next->next, elem2);
    /* 21 */ ASSERT_EQ_PTR(lst->next->next->content, s2);
    /* 22 */ ASSERT_EQ_PTR(lst->next->next->next, elem1);
    /* 23 */ ASSERT_EQ_PTR(lst->next->next->next->content, s1);
    /* 24 */ ASSERT_EQ_PTR(lst->next->next->next->next, NULL);

    /* Add front #5 */
    ft_lstadd_front(&lst, elem5);
    /* 25 */ ASSERT_EQ_PTR(lst, elem5);
    /* 26 */ ASSERT_EQ_PTR(lst->content, &val5);
    /* 27 */ ASSERT_EQ_PTR(lst->next, elem4);
    /* 28 */ ASSERT_EQ_PTR(lst->next->content, &val4);
    /* 29 */ ASSERT_EQ_PTR(lst->next->next, elem3);
    /* 30 */ ASSERT_EQ_PTR(lst->next->next->content, s3);
    /* 31 */ ASSERT_EQ_PTR(lst->next->next->next, elem2);
    /* 32 */ ASSERT_EQ_PTR(lst->next->next->next->content, s2);
    /* 33 */ ASSERT_EQ_PTR(lst->next->next->next->next, elem1);
    /* 34 */ ASSERT_EQ_PTR(lst->next->next->next->next->content, s1);
    /* 35 */ ASSERT_EQ_PTR(lst->next->next->next->next->next, NULL);
	return (0);
}

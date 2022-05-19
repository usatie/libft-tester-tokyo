/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:22:17 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:05:32 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int counter = 0;
static void *freed = NULL;
static void cnt_free(void *p) {
    counter++;
    freed = p;
    free(p);
}

static void void_free(void *p) {
    counter++;
    freed = p;
}

int	main(void)
{
    t_list  *elem1 = calloc(sizeof(t_list), 1);
    t_list  *elem2 = calloc(sizeof(t_list), 1);
    t_list  *elem3 = calloc(sizeof(t_list), 1);
    t_list  *elem4 = calloc(sizeof(t_list), 1);
    t_list  *elem5 = calloc(sizeof(t_list), 1);
    char    *s1 = strdup("hello");
    char    *s2 = strdup("world");
    char    *s3 = strdup("42!");
    int     val4 = 42;
    int     val5 = -42;
    elem1->content = s1;
    elem2->content = s2;
    elem3->content = s3;
    elem4->content = &val4;
    elem5->content = &val5;

    /* size = 0 */
    t_list  *lst = NULL;
    ft_lstdelone(lst, cnt_free);
    /* 1 */ ASSERT_EQ_PTR(lst, NULL);
    /* 2 */ ASSERT_EQ_I(counter, 0);


    /* size = 1 */
    lst = elem1;
    ft_lstdelone(lst, cnt_free);
    /* 3 */ ASSERT_EQ_PTR(lst, elem1);
    /* 4 */ ASSERT_EQ_I(counter, 1);
    /* 5 */ ASSERT_EQ_PTR(freed, s1);

    /* size = 4 */
    lst = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
    elem4->next = elem5;
    ft_lstdelone(lst, cnt_free);
    /* 6 */ ASSERT_EQ_PTR(lst, elem2);
    /* 7 */ ASSERT_EQ_I(counter, 2);
    /* 8 */ ASSERT_EQ_PTR(freed, s2);

    ft_lstdelone(elem5, void_free);
    /* 9 */ ASSERT_EQ_PTR(lst, elem2);
    /* 10 */ ASSERT_EQ_I(counter, 3);
    /* 11 */ ASSERT_EQ_PTR(freed, &val5);

    // Segmentaiton Fault
    // /* */ ft_lstdelone(elem4, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:53:53 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:05:23 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int counter = 0;
static void *freed[10] = {};
static void cnt_free(void *p) {
    freed[counter++] = p;
    free(p);
}

static void void_free(void *p) {
    freed[counter++] = p;
}

static int contains(void *arr[10], void *p)
{
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == p)
            return (1);
    }
    return (0);
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
    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
    elem4->next = elem5;

    /* size = 0 */
    t_list  *lst = NULL;
    ft_lstclear(&lst, cnt_free);
    /* 1 */ ASSERT_EQ_PTR(lst, NULL);
    /* 2 */ ASSERT_EQ_I(counter, 0);


    /* size = 2 */
    lst = elem4;
    ft_lstclear(&lst, void_free);
    /* 3 */ ASSERT_EQ_PTR(lst, NULL);
    /* 4 */ ASSERT_EQ_I(counter, 2);
    /* 5 */ ASSERT_TRUE(contains(freed, &val5));

    /* size = 3 */
    lst = elem1;
    elem3->next = NULL;
    ft_lstclear(&lst, cnt_free);
    /* 6 */ ASSERT_EQ_PTR(lst, NULL);
    /* 7 */ ASSERT_EQ_I(counter, 5);
    /* 8 */ ASSERT_TRUE(contains(freed, s1));
    /* 9 */ ASSERT_TRUE(contains(freed, s2));
    /* 10 */ ASSERT_TRUE(contains(freed, s3));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:19:04 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:05:54 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
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

    /* zero */
    t_list  *lst = NULL;
    /* 1 */ ASSERT_EQ_PTR(ft_lstlast(lst), NULL);

    /* add back #1 */
    lst = elem1;
    /* 2 */ ASSERT_EQ_PTR(ft_lstlast(lst), elem1);
    
    /* add back #2 */
    elem1->next = elem2;
    /* 3 */ ASSERT_EQ_PTR(ft_lstlast(lst), elem2);

    /* add back #3 */
    elem2->next = elem3;
    /* 4 */ ASSERT_EQ_PTR(ft_lstlast(lst), elem3);

    /* add back #4 */
    elem3->next = elem4;
    /* 5 */ ASSERT_EQ_PTR(ft_lstlast(lst), elem4);

    /* add back #5 */
    elem4->next = elem5;
    /* 6 */ ASSERT_EQ_PTR(ft_lstlast(lst), elem5);

    /* unlink #1->#2 */
    elem1->next = NULL;
    /* 7 */ ASSERT_EQ_PTR(ft_lstlast(lst), elem1);
}

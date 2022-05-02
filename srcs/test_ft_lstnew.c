/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:39:54 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:06:15 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
    t_list  *lst = NULL;
    
    /* ptr to char */
    char *str = "hello world";
    lst = ft_lstnew(str);
    /* 1 */ ASSERT_EQ_PTR(lst->content, str);
    /* 2 */ ASSERT_EQ_PTR(lst->next, NULL);

    /* ptr to int */
    int val = 100;
    lst = ft_lstnew(&val);
    /* 3 */ ASSERT_EQ_PTR(lst->content, &val);
    /* 4 */ ASSERT_EQ_PTR(lst->next, NULL);

    /* NULL */
    lst = ft_lstnew(NULL);
    /* 5 */ ASSERT_EQ_PTR(lst->content, NULL);
    /* 6 */ ASSERT_EQ_PTR(lst->next, NULL);
	return (0);
}

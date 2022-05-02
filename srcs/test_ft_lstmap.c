/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:33:52 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:06:05 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void *str_toupper(void *p)
{
    char *str = strdup((char *)p);
    char *tmp = str;
    while (*tmp)
    {
        *tmp = toupper(*tmp);
        tmp++;
    }
    return (str);
}

static void *str_tolower(void *p)
{
    char *str = strdup((char *)p);
    char *tmp = str;
    while (*tmp)
    {
        *tmp = tolower(*tmp);
        tmp++;
    }
    return (str);
}

int	main(void)
{
    t_list  *lst = ft_lstnew(strdup("Hello"));
    ft_lstadd_back(&lst, ft_lstnew(strdup(" World")));
    ft_lstadd_back(&lst, ft_lstnew(strdup(" 42")));
    ft_lstadd_back(&lst, ft_lstnew(strdup(" Tokyo!")));
    ft_lstadd_back(&lst, ft_lstnew(strdup("")));

    // toupper
    t_list *newlst = ft_lstmap(lst, str_toupper, free);
    /* 1 */ ASSERT_EQ_STR(newlst->content, "HELLO");
    /* 2 */ ASSERT_EQ_STR(newlst->next->content, " WORLD");
    /* 3 */ ASSERT_EQ_STR(newlst->next->next->content, " 42");
    /* 4 */ ASSERT_EQ_STR(newlst->next->next->next->content, " TOKYO!");
    /* 5 */ ASSERT_EQ_STR(newlst->next->next->next->next->content, "");
    /* 6 */ ASSERT_EQ_PTR(newlst->next->next->next->next->next, NULL);

    // tolower
    newlst = ft_lstmap(lst, str_tolower, free);
    /* 7 */ ASSERT_EQ_STR(newlst->content, "hello");
    /* 8 */ ASSERT_EQ_STR(newlst->next->content, " world");
    /* 9 */ ASSERT_EQ_STR(newlst->next->next->content, " 42");
    /* 10 */ ASSERT_EQ_STR(newlst->next->next->next->content, " tokyo!");
    /* 11 */ ASSERT_EQ_STR(newlst->next->next->next->next->content, "");
    /* 12 */ ASSERT_EQ_PTR(newlst->next->next->next->next->next, NULL);
}

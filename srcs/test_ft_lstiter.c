/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:27:05 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:05:40 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void str_toupper(void *p)
{
    char *str = (char *)p;
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

static void str_tolower(void *p)
{
    char *str = (char *)p;
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

int	main(void)
{
    t_list  *lst = ft_lstnew(strdup("Hello"));
    ft_lstadd_back(&lst, ft_lstnew(strdup(" World")));
    ft_lstadd_back(&lst, ft_lstnew(strdup(" 42")));
    ft_lstadd_back(&lst, ft_lstnew(strdup(" Tokyo!")));
    ft_lstadd_back(&lst, ft_lstnew(strdup("")));

    
    // toupper
    ft_lstiter(lst, str_toupper);
    /* 1 */ ASSERT_EQ_STR(lst->content, "HELLO");
    /* 2 */ ASSERT_EQ_STR(lst->next->content, " WORLD");
    /* 3 */ ASSERT_EQ_STR(lst->next->next->content, " 42");
    /* 4 */ ASSERT_EQ_STR(lst->next->next->next->content, " TOKYO!");
    /* 5 */ ASSERT_EQ_STR(lst->next->next->next->next->content, "");
    /* 6 */ ASSERT_EQ_PTR(lst->next->next->next->next->next, NULL);

    // tolower
    ft_lstiter(lst, str_tolower);
    /* 7 */ ASSERT_EQ_STR(lst->content, "hello");
    /* 8 */ ASSERT_EQ_STR(lst->next->content, " world");
    /* 9 */ ASSERT_EQ_STR(lst->next->next->content, " 42");
    /* 10 */ ASSERT_EQ_STR(lst->next->next->next->content, " tokyo!");
    /* 11 */ ASSERT_EQ_STR(lst->next->next->next->next->content, "");
    /* 12 */ ASSERT_EQ_PTR(lst->next->next->next->next->next, NULL);
}

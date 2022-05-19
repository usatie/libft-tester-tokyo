/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:38:44 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:08:32 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
    remove("tmp.txt");
    int fd = open("tmp.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    char    buf[1024];
    ft_putstr_fd("hello", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 1 */ ASSERT_EQ_STR(buf, "hello");
    ft_putstr_fd(" world", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 2 */ ASSERT_EQ_STR(buf, "hello world");
    ft_putstr_fd(" 42!", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 3 */ ASSERT_EQ_STR(buf, "hello world 42!");
    ft_putstr_fd("\0\0\0", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 4 */ ASSERT_EQ_STR(buf, "hello world 42!");
    ft_putstr_fd("\n\n\n", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 5 */ ASSERT_EQ_STR(buf, "hello world 42!\n\n\n");
    ft_putstr_fd("", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 6 */ ASSERT_EQ_STR(buf, "hello world 42!\n\n\n");
    close(fd);
    remove("tmp.txt");
	return (0);
}

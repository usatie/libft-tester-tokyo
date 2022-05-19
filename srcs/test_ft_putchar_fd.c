/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:54:15 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:07:38 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
    remove("tmp.txt");
    int fd = open("tmp.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    char    buf[1024];
    bzero(buf, 1024); ft_putchar_fd('a', fd); lseek(fd, 0, SEEK_SET); read(fd, buf, 1);
    /* 1 */ ASSERT_EQ_STR(buf, "a");
    bzero(buf, 1024); ft_putchar_fd('b', fd); lseek(fd, 0, SEEK_SET); read(fd, buf, 2);
    /* 2 */ ASSERT_EQ_STR(buf, "ab");
    bzero(buf, 1024); ft_putchar_fd('c', fd); lseek(fd, 0, SEEK_SET); read(fd, buf, 3);
    /* 3 */ ASSERT_EQ_STR(buf, "abc");
    bzero(buf, 1024); ft_putchar_fd('\n', fd); lseek(fd, 0, SEEK_SET); read(fd, buf, 4);
    /* 4 */ ASSERT_EQ_STR(buf, "abc\n");
    bzero(buf, 1024); ft_putchar_fd('\0', fd); lseek(fd, 0, SEEK_SET); read(fd, buf, 5);
    /* 5 */ ASSERT_EQ_STR(buf, "abc\n");
    close(fd);
    remove("tmp.txt");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:51:02 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:08:16 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
    remove("tmp.txt");
    int fd = open("tmp.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    char    buf[1024];
    ft_putnbr_fd(0, fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 1 */ ASSERT_EQ_STR(buf, "0");
    ft_putnbr_fd(1, fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 2 */ ASSERT_EQ_STR(buf, "01");
    ft_putnbr_fd(-1, fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 3 */ ASSERT_EQ_STR(buf, "01-1");
    ft_putnbr_fd(42, fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 4 */ ASSERT_EQ_STR(buf, "01-142");
    ft_putnbr_fd(-42, fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 5 */ ASSERT_EQ_STR(buf, "01-142-42");
    ft_putnbr_fd(INT_MAX, fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 6 */ ASSERT_EQ_STR(buf, "01-142-422147483647");
    ft_putnbr_fd(INT_MIN, fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 7 */ ASSERT_EQ_STR(buf, "01-142-422147483647-2147483648");
    ft_putnbr_fd(INT_MAX - 1, fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 8 */ ASSERT_EQ_STR(buf, "01-142-422147483647-21474836482147483646");
    ft_putnbr_fd(INT_MIN + 1, fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 9 */ ASSERT_EQ_STR(buf, "01-142-422147483647-21474836482147483646-2147483647");
    close(fd);
    remove("tmp.txt");
	return (0);
}

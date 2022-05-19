/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:47:50 by susami            #+#    #+#             */
/*   Updated: 2022/05/02 10:08:09 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
    remove("tmp.txt");
    int fd = open("tmp.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    char    buf[1024];
    ft_putendl_fd("hello", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 1 */ ASSERT_EQ_STR(buf, "hello\n");
    ft_putendl_fd(" world", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 2 */ ASSERT_EQ_STR(buf, "hello\n world\n");
    ft_putendl_fd(" 42!", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 3 */ ASSERT_EQ_STR(buf, "hello\n world\n 42!\n");
    ft_putendl_fd("\0\0\0", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 4 */ ASSERT_EQ_STR(buf, "hello\n world\n 42!\n\n");
    ft_putendl_fd("\n\n\n", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 5 */ ASSERT_EQ_STR(buf, "hello\n world\n 42!\n\n\n\n\n\n");
    ft_putendl_fd("", fd); lseek(fd, 0, SEEK_SET); bzero(buf, 1024); read(fd, buf, 1024);
    /* 6 */ ASSERT_EQ_STR(buf, "hello\n world\n 42!\n\n\n\n\n\n\n");
    close(fd);
    remove("tmp.txt");
	return (0);
}

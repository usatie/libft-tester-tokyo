/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:47:36 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 12:25:38 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

#ifdef __linux__
# include <bsd/string.h>
# include <stdint.h>
# include <sys/stat.h>
#else
# include <string.h>
#endif

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include "libft.h"
# include "libassert.h"

#endif

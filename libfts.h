/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:54:53 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/11 17:48:32 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTS_H_
# define _LIBFTS_H_

# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>


void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
size_t				ft_strlen(const char *s);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_puts(const char *s);

/*
**				TEST_BZERO.C
*/
int				test_bzero(void);
int				valid_test_bzero(void);
int				crash_test_bzero(void);
int				crash_test_bzero_2(void);

/*
**				TEST_STRCAT.C
*/
int				test_strcat(void);

/*
**				TEST_STRLEN.C
*/
int				test_strlen(void);

/*
**				TEST_ISUPPER.C
*/
int				test_isupper(void);

/*
**				TEST_ISLOWER.C
*/
int				test_islower(void);

/*
**				TEST_ISALPHA.C
*/
int				test_isalpha(void);

/*
**				TEST_ISDIGIT.C
*/
int				test_isdigit(void);

/*
**				TEST_ISALNUM.C
*/
int				test_isalnum(void);

/*
**				TEST_ISASCII.C
*/
int				test_isascii(void);

/*
**				TEST_ISPRINT.C
*/
int				test_isprint(void);

/*
**				TEST_TOUPPER.C
*/
int				test_toupper(void);

/*
**				TEST_TOLOWER.C
*/
int				test_tolower(void);

/*
**				TEST_PUTS.C
*/
int				test_puts(void);

#endif


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
void            *ft_memset(void *b, int c, size_t len);
void            *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char            *ft_strdup(const char *s1);
void            ft_cat(int fd);
void            *ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
char			*ft_strclr(char *s);
void 			ft_cat_bis(int fd);

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
int				valid_test_strcat(void);
int				crash_test_strcat(char *s1, char *s2);
char			*init_s0(void);
char			*init_s1(void);

/*
**				TEST_STRLEN.C
*/
int				test_strlen(void);
int				valid_test_strlen(void);
int				crash_test_strlen(void);
int				crash_test_strlen_2(void);

/*
**				TEST_ISUPPER.C
*/
int				test_isupper(void);
int				valid_test_isupper(void);

/*
**				TEST_ISLOWER.C
*/
int				test_islower(void);
int				valid_test_islower(void);

/*
**				TEST_ISALPHA.C
*/
int				test_isalpha(void);
int				valid_test_isalpha(void);

/*
**				TEST_ISDIGIT.C
*/
int				test_isdigit(void);
int				valid_test_isdigit(void);

/*
**				TEST_ISALNUM.C
*/
int				test_isalnum(void);
int				valid_test_isalnum(void);

/*
**				TEST_ISASCII.C
*/
int				test_isascii(void);
int				valid_test_isascii(void);

/*
**				TEST_ISPRINT.C
*/
int				test_isprint(void);
int				valid_test_isprint(void);

/*
**				TEST_TOUPPER.C
*/
int				test_toupper(void);
int				valid_test_toupper(void);

/*
**				TEST_TOLOWER.C
*/
int				test_tolower(void);
int				valid_test_tolower(void);

/*
**				TEST_PUTS.C
*/
int				test_puts(void);
int				valid_test_puts(void);
int				crash_test_puts(void);
int				crash_test_puts_2(void);

/*
**              TEST_STRDUP.C
*/
int             test_strdup(void);
int				valid_test_strdup(void);
int				crash_test_strdup(void);

/*
**              TEST_CAT.C
*/
int             test_cat(void);
int				valid_test_cat(void);
int				crash_test_cat(void);
int				crash_test_cat_2(void);

/*
**              TEST_MEMSET.C
*/
int             test_memset(void);
int				valid_test_memset(void);
int				crash_test_memset(void);

/*
**              TEST_MEMCPY.C
*/
int             test_memcpy(void);
int				valid_test_memcpy(void);
int				crash_test_memcpy(void);

/*
**              TEST_MEMALLOC.C
*/
int             test_memalloc(void);
int				valid_test_memalloc(void);
int				crash_test_memalloc(void);

/*
**				TEST_MEMDEL.C
*/
int				test_memdel(void);
int				valid_test_memdel(void);

/*
**				TEST_STRNEW.C
*/
int				test_strnew(void);
int				valid_test_strnew(void);
int				crash_test_strnew(void);

/*
**				TEST_STRDEL.C
*/
int				test_strdel(void);
int				valid_test_strdel(void);

/*
**				TEST_STRCLR.C
*/
int				test_strclr(void);
int				valid_test_strclr(void);

/*
**              TEST_FT_CAT_BIS.C
*/
int				test_cat_bis(void);
int				valid_test_cat_bis(void);
int				crash_test_cat_bis(void);
int				crash_test_cat_bis_2(void);

#endif

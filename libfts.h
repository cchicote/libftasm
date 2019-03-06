/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:54:53 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/06 20:56:57 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTS_H_
# define _LIBFTS_H_

# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <stdlib.h>


void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
size_t				ft_strlen(const char *s);

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

#endif


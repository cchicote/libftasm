/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:14:50 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/18 19:14:52 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_memcpy = 0;

int				crash_test_memcpy(void)
{
	char		*z1;
	char		*z2;
    char        *original_1;
    char        *original_2;
	int			ret;
	int			ret2;

	z1 = strdup("abcd");
	original_1 = strdup(z1);
	z2 = strdup("efgh");
	if (print_tests_memcpy)
	{
		printf("Before memcpy crash test\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
	}
	memcpy(z1, z2, 0);
    z1 = strdup("abcd");
	original_2 = strdup(z1);
	z2 = strdup("efgh");
	ft_memcpy(z1, z2, 0);
	ret = memcmp(z1, z2, 0);
	ret2 = memcmp(original_1, original_2, 0);
	if (print_tests_memcpy)
	{
		printf("After memcpy crash test\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
		printf("Memcmp result:\t\t\t[%d]\n\t\t\t\t[%d]\n", ret, ret2);
	}
	return (ret > 0 || ret2 > 0);
}

int				valid_test_memcpy(void)
{
	char		*z1;
	char		*z2;
    char        *original_1;
    char        *original_2;
	int			len;
	int			ret;
	int			ret2;

	z1 = strdup("abcd");
	original_1 = strdup(z1);
	z2 = strdup("efgh");
	len = strlen(z1);
	if (print_tests_memcpy)
	{
		printf("Before memcpy valid test\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
	}
	memcpy(z1, z2, len);
    z1 = strdup("abcd");
	original_2 = strdup(z1);
	z2 = strdup("efgh");
	ft_memcpy(z1, z2, len);
	ret = memcmp(z1, z2, len);
	ret2 = memcmp(original_1, original_2, len);
	if (print_tests_memcpy)
	{
		printf("After memcpy valid test\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
		printf("Memcmp result:\t\t\t[%d]\n\t\t\t\t[%d]\n", ret, ret2);
	}
	return (ret > 0 || ret2 > 0);
}

int				test_memcpy(void)
{
	int			error_counter;

	error_counter = 0;
	valid_test_memcpy() != 0 ? error_counter++ : 0 ;
	crash_test_memcpy() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for memcpy tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_memcpy tests passed !\033[0m\n");
	return (error_counter);
}


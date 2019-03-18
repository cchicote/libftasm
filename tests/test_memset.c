/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:02:56 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/18 19:02:59 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_memset = 0;

int				crash_test_memset(void)
{
	char			*z1;
	char			*z2;
	int			len;
	int			ret;

	z1 = strdup("Bonjour");
	z2 = strdup("Bonjour");
	len = strlen(z1);
	if (print_tests_memset)
	{
		printf("Before memset crash test\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
	}
	memset(z1, 'a', 0);
	ft_memset(z2, 'a', 0);
	ret = memcmp(z1, z2, len);
	if (print_tests_memset)
	{
		printf("After memset crash test\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
		printf("Memcmp result:\t\t\t[%d]\n", ret);
	}
	return (ret);
}

int				valid_test_memset(void)
{
	char			*z1;
	char			*z2;
	int			len;
	int			ret;

	z1 = strdup("Bonjour");
	z2 = strdup("Bonjour");
	len = strlen(z1);
	if (print_tests_memset)
	{
		printf("Before memset valid test\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
	}
	memset(z1, 'a', len);
	ft_memset(z2, 'a', len);
	ret = memcmp(z1, z2, len);
	if (print_tests_memset)
	{
		printf("After memset valid test\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
		printf("Memcmp result:\t\t\t[%d]\n", ret);
	}
	return (ret);
}

int				test_memset(void)
{
	int			error_counter;

	error_counter = 0;
	valid_test_memset() != 0 ? error_counter++ : 0 ;
	crash_test_memset() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for memset tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_memset tests passed !\033[0m\n");
	return (error_counter);
}

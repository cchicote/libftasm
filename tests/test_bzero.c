/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:09:34 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/07 14:01:51 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests = 0;

int				crash_test_bzero(void)
{
	char			*z1;
	char			*z2;
	int			len;
	int			ret;

	z1 = strdup("Bonjour");
	z2 = strdup("Bonjour");
	len = strlen(z1);
	if (print_tests)
	{
		printf("Before bzero crash test\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
	}
	bzero(z1, 0);
	ft_bzero(z2, 0);
	ret = memcmp(z1, z2, len);
	if (print_tests)
	{
		printf("After bzero crash test\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
		printf("Memcmp result:\t\t\t[%d]\n", ret);
	}
	return (ret);
}

int				crash_test_bzero_2(void)
{
	char			*z1;
	char			*z2;
	int			len;
	int			ret;

	z1 = strdup("Bonjour");
	z2 = strdup("Bonjour");
	len = strlen(z1);
	if (print_tests)
	{
		printf("Before bzero crash test 2\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
	}
	bzero(z1, len + 100);
	ft_bzero(z2, len + 100);
	ret = memcmp(z1, z2, len);
	if (print_tests)
	{
		printf("After bzero crash test 2\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
		printf("Memcmp result:\t\t\t[%d]\n", ret);
	}
	return (ret);
}

int				valid_test_bzero(void)
{
	char			*z1;
	char			*z2;
	int			len;
	int			ret;

	z1 = strdup("Bonjour");
	z2 = strdup("Bonjour");
	len = strlen(z1);
	if (print_tests)
	{
		printf("Before bzero valid test\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
	}
	bzero(z1, len);
	ft_bzero(z2, len);
	ret = memcmp(z1, z2, len);
	if (print_tests)
	{
		printf("After bzero valid test\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
		printf("Memcmp result:\t\t\t[%d]\n", ret);
	}
	return (ret);
}

int				test_bzero(void)
{
	int			error_counter;

	error_counter = 0;
	valid_test_bzero() != 0 ? error_counter++ : 0 ;
	crash_test_bzero() != 0 ? error_counter++ : 0 ;
	//This one cause memory troubles even with the standard bzero
	//crash_test_bzero_2() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for bzero tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_bzero tests passed !\033[0m\n");
	return (error_counter);
}


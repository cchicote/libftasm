/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_puts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:09:34 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/11 19:01:52 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_puts = 0;

int				crash_test_puts_2(void)
{
	char			*z1;
	char			*z2;
	int				ret1;
	int				ret2;

	z1 = NULL;
	z2 = NULL;
	if (print_tests_puts)
	{
		printf("Before puts crash test2\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
	}
	close(1);
	ret1 = puts(z1);
	ret2 = ft_puts(z2);
	if (print_tests_puts)
	{
		fprintf(stderr, "After puts crash test2\t\tz1: [%s]\n", z1);
		fprintf(stderr, "\t\t\t\tz2: [%s]\n", z2);
		fprintf(stderr, "Libc return values:\t\t[%d]\n", ret1);
		fprintf(stderr, "Ft return values:\t\t[%d]\n\n", ret2);
	}
	return (ret1 != ret2);
}

int				crash_test_puts(void)
{
	char			*z1;
	char			*z2;
	int				ret1;
	int				ret2;

	z1 = NULL;
	z2 = NULL;
	if (print_tests_puts)
	{
		printf("Before puts crash test\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
	}
	ret1 = puts(z1);
	ret2 = ft_puts(z2);
	if (print_tests_puts)
	{
		fprintf(stderr, "After puts crash test1\t\tz1: [%s]\n", z1);
		fprintf(stderr, "\t\t\t\tz2: [%s]\n", z2);
		fprintf(stderr, "Libc return values:\t\t[%d]\n", ret1);
		fprintf(stderr, "Ft return values:\t\t[%d]\n\n", ret2);
	}
	return (ret1 != ret2);
}

int				valid_test_puts(void)
{
	char			*z1;
	char			*z2;
	int				ret1;
	int				ret2;

	z1 = strdup("valid_test_puts1");
	z2 = strdup("valid_test_puts2");
	if (print_tests_puts)
	{
		printf("Before puts valid test\t\tz1: [%s]\n", z1);
		printf("\t\t\t\tz2: [%s]\n", z2);
	}
	ret1 = puts(z1);
	ret2 = ft_puts(z2);
	if (print_tests_puts)
	{
		fprintf(stderr, "After puts valid test\t\tz1: [%s]\n", z1);
		fprintf(stderr, "\t\t\t\tz2: [%s]\n", z2);
		fprintf(stderr, "Libc return values:\t\t[%d]\n", ret1);
		fprintf(stderr, "Ft return values:\t\t[%d]\n\n", ret2);
	}
	return (ret1 != ret2);
}

int				test_puts(void)
{
	int			error_counter;

	error_counter = 0;
	valid_test_puts() != 0 ? error_counter++ : 0 ;
	crash_test_puts() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for puts tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_puts tests passed !\033[0m\n");
	return (error_counter);
}


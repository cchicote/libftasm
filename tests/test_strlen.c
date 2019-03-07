/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:50:11 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/06 22:23:17 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int				print_strlen_tests = 0;

int				crash_test_strlen(void)
{
	char			*s1;
	size_t			ret1;
	size_t			ret2;

	s1 = strdup("");
	if (print_strlen_tests)
	{
		printf("Test string: [%s]\n", s1);
	}
	ret1 = strlen(s1);
	ret2 = ft_strlen(s1);
	if (print_strlen_tests)
	{
		printf("libc strlen:\t[%zu]\n", ret1);
		printf("ft_strlen:\t[%zu]\n", ret2);
	}
	return (ret1 != ret2);
}

int				valid_test_strlen(void)
{
	char			*s1;
	size_t			ret1;
	size_t			ret2;

	s1 = strdup("123456789");
	if (print_strlen_tests)
	{
		printf("Test string: [%s]\n", s1);
	}
	ret1 = strlen(s1);
	ret2 = ft_strlen(s1);
	if (print_strlen_tests)
	{
		printf("libc strlen:\t[%zu]\n", ret1);
		printf("ft_strlen:\t[%zu]\n", ret2);
	}
	return (ret1 != ret2);
}

int				test_strlen(void)
{
	int			error_counter;

	error_counter = 0;
	valid_test_strlen() != 0 ? error_counter++ : 0 ;
	crash_test_strlen() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for strlen tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_strlen tests passed !\033[0m\n");
	return (0);
}

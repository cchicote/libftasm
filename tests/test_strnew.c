/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:02:56 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/18 19:02:59 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_strnew = 0;

int				crash_test_strnew(void)
{
	char		*z1;

	z1 = ft_strnew(0);
	return (z1 != NULL);
}

int				valid_test_strnew(void)
{
	char		*z1;
	int			size;

	size = 17;
	z1 = ft_strnew(size);
	if (!z1)
		return (1);
	ft_memset(z1, 'a', size);
	z1[size - 2] = 'b';
	if (print_tests_strnew)
	{
		printf("[%s]\n", z1);
	}
	return (0);
}

int				test_strnew(void)
{
	int			error_counter;

	error_counter = 0;
	valid_test_strnew() != 0 ? error_counter++ : 0 ;
	crash_test_strnew() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for strnew tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_strnew tests passed !\033[0m\n");
	return (error_counter);
}

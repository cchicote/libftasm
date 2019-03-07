/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:55:16 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/08 00:19:12 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_tolower = 0;

int			valid_test_tolower(void)
{
	int		error_counter;
	int		ret_libc;
	int		ret_ft;
	int		c;

	error_counter = 0;
	c = 0;
	while (c <= 127)
	{
		ret_libc = tolower(c);
		ret_ft = ft_tolower(c);
		if (ret_libc != ret_ft)
		{
			error_counter++;
			if (print_tests_tolower)
				printf("ft_tolower: Invalid result for [%c] ([%d])\n", c, c);
		}
		c++;
	}
	return (error_counter);
}

int			test_tolower(void)
{
	int		error_counter;

	error_counter = 0;
	valid_test_tolower() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for tolower tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_tolower tests passed !\033[0m\n");
	return (0);
}


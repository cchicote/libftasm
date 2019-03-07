/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:55:16 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/07 23:32:24 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_isdigit = 0;

int			valid_test_isdigit(void)
{
	int		error_counter;
	int		ret_libc;
	int		ret_ft;
	int		c;

	error_counter = 0;
	c = 0;
	while (c <= 127)
	{
		ret_libc = isdigit(c);
		ret_ft = ft_isdigit(c);
		if (ret_libc != ret_ft)
		{
			error_counter++;
			if (print_tests_isdigit)
				printf("ft_isdigit: Invalid result for [%c] ([%d])\n", c, c);
		}
		c++;
	}
	return (error_counter);
}

int			test_isdigit(void)
{
	int		error_counter;

	error_counter = 0;
	valid_test_isdigit() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for isdigit tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_isdigit tests passed !\033[0m\n");
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:09:34 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/11 19:01:52 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_cat = 0;

int				valid_test_cat(void)
{
	int			fd;

	fd = open("test.txt", O_RDONLY, S_IREAD);
	ft_cat(fd);
	close(fd);
	return (0);
}

int				crash_test_cat(void)
{
	ft_cat(42);
	return (0);
}

int				crash_test_cat_2(void)
{
	ft_cat(1);
	return (0);
}

int				test_cat(void)
{
	int			error_counter;

	error_counter = 0;
	valid_test_cat() != 0 ? error_counter++ : 0 ;
	//crash_test_cat() != 0 ? error_counter++ : 0 ;
	//crash_test_cat_2() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for cat tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_cat tests passed !\033[0m\n");
	return (error_counter);
}


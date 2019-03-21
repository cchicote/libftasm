/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:02:56 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/18 19:02:59 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_strdel = 0;

int				valid_test_strdel(void)
{
	char		*z1;
	
	z1 = strdup("Bonjour");
	if (print_tests_strdel)
		ft_puts(z1);
	ft_strdel(&z1);
	if (print_tests_strdel)
		ft_puts(z1);
	free(z1);
	if (print_tests_strdel)
		ft_puts(z1);
	return (0);
}

int				test_strdel(void)
{
	int			error_counter;

	error_counter = 0;
	valid_test_strdel() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for strdel tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_strdel tests passed !\033[0m\n");
	return (error_counter);
}

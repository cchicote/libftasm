/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strclr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:02:56 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/18 19:02:59 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_strclr = 0;

int				valid_test_strclr(void)
{
	char		*z1;
	
	z1 = strdup("Bonjour");
	if (print_tests_strclr)
		ft_puts(z1);
	ft_strclr(z1);
	if (print_tests_strclr)
		ft_puts(z1);
	free(z1);
	if (print_tests_strclr)
		ft_puts(z1);
	return (0);
}

int				test_strclr(void)
{
	int			error_counter;

	error_counter = 0;
	valid_test_strclr() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for strclr tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_strclr tests passed !\033[0m\n");
	return (error_counter);
}

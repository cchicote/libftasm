/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:42:15 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/12 17:41:22 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_strdup = 0;

int			valid_test_strdup(void)
{
	int		ret_value;
	char	*s1;
	char	*s2;

	s1 = strdup("Coucou");
	s2 = ft_strdup("Coucou");
	if (print_tests_strdup)
		printf("s1: [%s]\ns2: [%s]\n", s1, s2);
	ret_value = strcmp(s1, s2);
	if (print_tests_strdup)
		printf("ret value: [%d]\n", ret_value);
	return (ret_value);
}

int			crash_test_strdup(void)
{
	int		ret_value;
	char	*s1;
	char	*s2;

	s1 = strdup("");
	s2 = strdup("");
	if (print_tests_strdup)
		printf("s1: [%s]\ns2: [%s]\n", s1, s2);
	ret_value = strcmp(s1, s2);
	if (print_tests_strdup)
		printf("ret value: [%d]\n", ret_value);
	return (ret_value);
}

int			test_strdup(void)
{
	int		error_counter;

	error_counter = 0;
	valid_test_strdup() != 0 ? error_counter++ : 0 ;
	crash_test_strdup() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for strdup tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_strdup tests passed !\033[0m\n");
	return (0);
}


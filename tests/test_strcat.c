/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:42:15 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/12 17:41:22 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_strcat = 0;

char			*init_s1(void)
{
	char		*s1;

	s1 = (char*)malloc(sizeof(char) * 100);
	bzero(s1, 100);
	strcpy(s1, "[Bonjour je suis un debut de string]");
	return (s1);
}

char			*init_s0(void)
{
	char		*s0;

	s0 = (char*)malloc(sizeof(char) * 100);
	s0[0] = 0;
	return (s0);
}

int			crash_test_strcat(char *s1, char *s2)
{
	char		*s0;
	char		*s0_2;
	char		*ret_libc;
	char		*ret_ft;
	int		ret;

	s0 = init_s0();
	if (print_tests_strcat)
		printf("s0: [%s]\ns1: [%s]\ns2: [%s]\n", s0, s1, s2);
	s0 = strcat(s0, s1);
	if (print_tests_strcat)
	{
		printf("After strcat 1:\n");
		printf("s0: [%s]\ns1: [%s]\ns2: [%s]\n", s0, s1, s2);
	}
	s0 = strcat(s0, s2);
	if (print_tests_strcat)
	{
		printf("After strcat 2:\n");
		printf("s0: [%s]\ns1: [%s]\ns2: [%s]\n\n", s0, s1, s2);
	}
	ret_libc = strdup(s0);

	s0_2 = init_s0();	
	if (print_tests_strcat)
		printf("s0: [%s]\ns1: [%s]\ns2: [%s]\n", s0_2, s1, s2);
	s0_2 = ft_strcat(s0_2, s1);
	if (print_tests_strcat)
	{
		printf("After ft_strcat 1:\n");
		printf("s0: [%s]\ns1: [%s]\ns2: [%s]\n", s0_2, s1, s2);
	}
	s0_2 = ft_strcat(s0_2, s2);
	if (print_tests_strcat)
	{
		printf("After ft_strcat 2:\n");
		printf("s0: [%s]\ns1: [%s]\ns2: [%s]\n\n", s0_2, s1, s2);
	}
	ret_ft = strdup(s0_2);

	ret = strcmp(ret_libc, ret_ft);
	if (print_tests_strcat)
		printf("strcmp result: [%d]\n\n", ret);
	return (ret);
}

int			valid_test_strcat(void)
{
	char		*ret_libc;
	char		*ret_ft;
	char		*s1;
	char		*s2;
	int		ret;

	s1 = init_s1();
	s2 = strdup("[Et moi une fin de string]");
	if (print_tests_strcat)
		printf("s1: [%s]\ns2: [%s]\n\n", s1, s2);
	ret_libc = strcat(s1, s2);
	if (print_tests_strcat)
	{
		printf("After strcat:\n");
		printf("s1: [%s]\ns2: [%s]\n", s1, s2);
		printf("ret: [%s]\n\n", ret_libc);
	}
	free(s1);
	free(s2);	
	s1 = init_s1();
	s2 = strdup("[Et moi une fin de string]");
	ret_ft = ft_strcat(s1, s2);
	if (print_tests_strcat)
	{
		printf("After ft_strcat:\n");
		printf("s1: [%s]\ns2: [%s]\n", s1, s2);
		printf("ret: [%s]\n\n", ret_libc);
	}
	ret = strcmp(ret_libc, ret_ft);
	if (print_tests_strcat)
		printf("strcmp result: [%d]\n\n", ret);
	return (ret);
}

int			test_strcat(void)
{
	int		error_counter;

	error_counter = 0;
	//valid_test_strcat() != 0 ? error_counter++ : 0 ;
	crash_test_strcat("Bonjour je suis un debut ", "de string!") != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for strcat tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_strcat tests passed !\033[0m\n");
	return (0);
}


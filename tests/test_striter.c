/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:42:15 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/12 17:41:22 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"
#include <unistd.h>

int print_tests_striter = 0;

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_striter_bis(char *s, void (*f)(char *))
{
	int index;

	index = 0;
	if (s != NULL && f != NULL)
	{
		while (s[index] != '\0')
		{
			(*f)(&s[index]);
			index++;
		}
	}
}

int			valid_test_striter(void)
{
	char	*str;

	str = ft_strdup("Bonjour\n");
	ft_striter(str, &ft_putstr);
	return (0);
}

int			test_striter(void)
{
	int		error_counter;

	error_counter = 0;
	valid_test_striter() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for striter tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_striter tests passed !\033[0m\n");
	return (0);
}


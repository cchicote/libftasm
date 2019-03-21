/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cat_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 00:21:51 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/22 00:22:01 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>

int					valid_test_cat_bis(void)
{
	int			fd;

	fd = open("test.txt", O_RDONLY, S_IREAD);
	ft_cat_bis(fd);
	close(fd);
	return (0);
}

int				crash_test_cat_bis(void)
{
	ft_cat_bis(42);
	return (0);
}

int				crash_test_cat_bis_2(void)
{
	ft_cat_bis(1);
	return (0);
}

int					test_cat_bis(void)
{
	int		error_counter;

	error_counter = 0;
	valid_test_cat_bis() != 0 ? error_counter++ : 0 ;
	crash_test_cat_bis() != 0 ? error_counter++ : 0 ;
	crash_test_cat_bis_2() != 0 ? error_counter++ : 0 ;
	if (error_counter)
		printf("\033[01;31m%d tests failed for ft_cat_bis tests\033[0m\n", error_counter);
	else
		printf("\033[01;32mAll ft_cat_bis tests passed !\033[0m\n");
	return (0);
}

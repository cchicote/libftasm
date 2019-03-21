/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:57:32 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/11 19:24:55 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfts.h"

int				main(void)
{
	int			total_errors;

	total_errors = 0;
	printf("\033[01;33m--- Mandatory functions: ---\033[0m\n");
	total_errors += test_bzero();
	total_errors += test_strcat();
	total_errors += test_strlen();
	total_errors += test_isalpha();
	total_errors += test_isdigit();
	total_errors += test_isalnum();
	total_errors += test_isascii();
	total_errors += test_isprint();
	total_errors += test_toupper();
	total_errors += test_tolower();
	total_errors += test_strdup();
	total_errors += test_memset();
	total_errors += test_memcpy();
	total_errors += test_cat();
	total_errors += test_puts();
	printf("\033[01;33m\n--- Bonus functions: ---\033[0m\n");
	total_errors += test_memalloc();
	total_errors += test_memdel();
	total_errors += test_strnew();
	total_errors += test_isupper();
	total_errors += test_islower();
	total_errors += test_strdel();
	total_errors += test_strclr();
	total_errors += test_cat_bis();
	printf("\033[01;33m\nTotal errors: [%d]\033[0m\n", total_errors);
	
	return (0);	
}

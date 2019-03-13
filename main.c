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
	total_errors += test_bzero();
	total_errors += test_strcat();
	total_errors += test_strlen();
	total_errors += test_isupper();
	total_errors += test_islower();
	total_errors += test_isalpha();
	total_errors += test_isdigit();
	total_errors += test_isalnum();
	total_errors += test_isascii();
	total_errors += test_isprint();
	total_errors += test_toupper();
	total_errors += test_tolower();
	total_errors += test_strdup();
	total_errors += test_cat();
	//total_errors += test_puts();
	printf("\033[01;33mTotal errors: [%d]\033[0m\n", total_errors);
	return (0);	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:57:32 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/06 22:14:04 by cchicote         ###   ########.fr       */
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
	printf("\033[01;33mTotal errors: [%d]\033[0m\n", total_errors);
	return (0);	
}

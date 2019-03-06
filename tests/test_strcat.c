/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:42:15 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/06 03:54:28 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_strcat = 1;

int			test_strcat(void)
{
	char		*s1;
	char		*s2;
	int		ret;

	s1 = strdup("Bonjour    ");
	s2 = strdup("        abc");
	ret = 0;
	if (print_tests_strcat)
	{
		printf("ft_strcat: [%s]\n", ft_strcat(s1, s2));
	}
	return (ret);
}


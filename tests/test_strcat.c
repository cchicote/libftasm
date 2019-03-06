/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 02:42:15 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/06 20:35:22 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int print_tests_strcat = 1;

void			strcat_example(char *s1, char *s2)
{
	printf("strcat: [%s]\n", strcat(s1, s2));
}

int			test_strcat(void)
{
	char		*s1;
	char		*s2;
	int		ret;

	s1 = (char*)malloc(sizeof(char) * 100);
	bzero(s1, 100);
	strcpy(s1, "on a de quoi faire");
	s2 = strdup("aaaaa yolo");
	ret = 0;
	if (print_tests_strcat)
	{
		strcat_example(strdup(s1), strdup(s2));
		printf("ft_strcat: [%s]\n", ft_strcat(s1, s2));
	}
	return (ret);
}


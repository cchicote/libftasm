/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:50:11 by cchicote          #+#    #+#             */
/*   Updated: 2019/03/06 21:31:18 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libfts.h"

int				test_strlen(void)
{
	char			*str;

	str = strdup("abcd");
	printf("strlen:\t\t[%zu]\n", strlen(str));
	printf("ft_strlen:\t[%zu]\n", ft_strlen(str));
	printf("[%s]\n", str);
	return (0);
}

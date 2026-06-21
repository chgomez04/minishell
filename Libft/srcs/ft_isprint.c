/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:55 by chgomez           #+#    #+#             */
/*   Updated: 2025/04/30 12:32:34 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Est ce un caractere imprimable*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int c;

	if (argc != 2)
	{
		printf("usage : ./exec <c>\n");
		return (1);
	}
	c = argv[1][0];
	if (ft_isprint(c) == 1)
		printf("%c is printable.\n", c);
	else
		printf("%c is not printable.\n", c);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:29:40 by chgomez           #+#    #+#             */
/*   Updated: 2025/05/15 12:05:51 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* is alpha or numeric
*/

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
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
	if (ft_isalnum(c) == 1)
		printf("%c is alnum.\n", c);
	else
		printf("%c is not alnum.\n", c);
	return (0);
}
*/	

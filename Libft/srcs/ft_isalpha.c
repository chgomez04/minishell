/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:18:45 by chgomez           #+#    #+#             */
/*   Updated: 2025/04/30 12:27:41 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*est une lettre*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	if (ft_isalpha(c) == 1)
		printf("%c is alpha.\n", c);
	else
		printf("%c is not alpha.\n", c);
	return (0);
}
*/

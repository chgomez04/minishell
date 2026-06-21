/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:05:28 by chgomez           #+#    #+#             */
/*   Updated: 2025/05/15 12:03:22 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* met a zero une portion de memoire*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}
/*
#include <stdio.h>

int	main()
{	
	char s[] = "je mange des pates";
	printf("OG s : %s\n", s);
	ft_bzero(s, 10);
	printf("new s : %s\n", s);
	return (0);
}
*/

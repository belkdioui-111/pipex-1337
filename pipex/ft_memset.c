/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:58:13 by bel-kdio          #+#    #+#             */
/*   Updated: 2022/12/08 20:18:09 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	*ft_memset(void *b, int c, size_t len)
{	
	size_t	i;

	i = len;
	while (len--)
		*(char *)b++ = (unsigned char )c;
	return (b - i);
}

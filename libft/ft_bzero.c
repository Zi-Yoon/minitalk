/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:06:12 by byan              #+#    #+#             */
/*   Updated: 2022/01/11 19:32:04 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = -1;
	tmp = (unsigned char *)dest;
	while (++i < len)
		tmp[i] = 0;
	return ;
}

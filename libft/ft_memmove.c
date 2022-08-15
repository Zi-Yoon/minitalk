/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:48:23 by byan              #+#    #+#             */
/*   Updated: 2022/01/11 19:32:23 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst == 0 && src == 0)
		return (0);
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst <= temp_src)
	{
		while (len)
		{
			*temp_dst++ = *temp_src++;
			len--;
		}
	}
	else
	{
		while (len)
		{
			len--;
			temp_dst[len] = temp_src[len];
		}
	}
	return (dst);
}

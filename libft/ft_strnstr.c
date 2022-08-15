/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:34:30 by byan              #+#    #+#             */
/*   Updated: 2022/01/11 19:33:54 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (needle[0] == '\0')
		return ((char *) haystack);
	while (*haystack != '\0' && len > 0)
	{
		i = 0;
		while (haystack[i] && needle[i] && haystack[i] == needle[i] && i < len)
			i++;
		if (needle[i] == '\0')
			return ((char *) haystack);
		haystack++;
		len--;
	}
	return (0);
}

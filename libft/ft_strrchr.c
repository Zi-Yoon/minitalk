/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:38:11 by byan              #+#    #+#             */
/*   Updated: 2022/01/11 21:52:00 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;

	temp = (char *)str;
	while (*str)
		str++;
	if (c == '\0')
		return ((char *)str);
	while (--str >= temp)
	{
		if (*str == (char) c)
			return ((char *)str);
	}
	return (0);
}

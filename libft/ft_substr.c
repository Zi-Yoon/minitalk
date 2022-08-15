/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 04:26:16 by byan              #+#    #+#             */
/*   Updated: 2022/01/11 19:33:59 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*tmp;

	s_len = ft_strlen(s);
	if (s_len <= start || len == 0 || s_len == 0)
		return ((char *) ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, s + start, len + 1);
	return (tmp);
}

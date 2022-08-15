/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:07:34 by byan              #+#    #+#             */
/*   Updated: 2022/01/15 04:03:32 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*tmp;

	if (!s1 || !set)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && find_set(s1[start], set))
		start++;
	while (end > start && find_set(s1[end], set))
		end--;
	tmp = (char *)malloc(sizeof(char) * (end - start) + 2);
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, s1 + start, end - start + 2);
	return (tmp);
}

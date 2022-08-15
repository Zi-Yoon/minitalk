/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 05:15:59 by byan              #+#    #+#             */
/*   Updated: 2022/01/11 19:32:17 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	ft_alphalen(int n)
{
	long long		num;
	unsigned char	len;

	if (n == 0)
		return (1);
	len = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static unsigned int	ft_pow(unsigned char n)
{
	unsigned int	ans;

	ans = 1;
	while (n--)
		ans *= 10;
	return (ans);
}

char	*ft_itoa(int n)
{
	long long		num;
	char			*ans;
	unsigned char	len;
	unsigned char	i;

	len = ft_alphalen(n);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == 0)
		return (0);
	i = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		ans[i++] = '-';
		len--;
	}
	while (len > 0)
	{	
		ans[i++] = (num / ft_pow(len - 1)) + '0';
		num %= ft_pow(len - 1);
		len--;
	}
	ans[i] = '\0';
	return (ans);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:29:39 by byan              #+#    #+#             */
/*   Updated: 2022/01/11 19:37:59 by byan             ###   ########seoul.kr  */
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

void	ft_putnbr_fd(int n, int fd)
{
	long long		num;
	unsigned char	len;
	unsigned char	c;

	len = ft_alphalen(n);
	num = n;
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
		len--;
	}
	while (len > 0)
	{
		c = (num / ft_pow(len - 1)) + '0';
		num %= ft_pow(len - 1);
		write(fd, &c, 1);
		len--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:05:21 by byan              #+#    #+#             */
/*   Updated: 2022/07/06 13:34:15 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	send_sig(pid_t pid, int sig)
{
	if (kill(pid, sig) != 0)
		print_error("PID error or Kill error");
	else
		usleep(125);
}

void	print_error(char *message)
{
	ft_putstr_fd("[ERROR] : ", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

void	print_pid(char *user)
{
	ft_putstr_fd("[", 1);
	ft_putstr_fd(user, 1);
	ft_putstr_fd(" PID] : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
}

char	*ft_str_charjoin(char *s1, char s2)
{
	size_t	len_s1;
	char	*tmp;
	int		i;

	if (!s1)
		return (0);
	len_s1 = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (len_s1 + 1 + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i++] = s2;
	tmp[i] = '\0';
	free(s1);
	return (tmp);
}

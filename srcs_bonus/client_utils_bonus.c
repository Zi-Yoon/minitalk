/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:05:21 by byan              #+#    #+#             */
/*   Updated: 2022/07/02 09:39:34 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

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

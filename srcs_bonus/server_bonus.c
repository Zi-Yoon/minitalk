/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:48:59 by byan              #+#    #+#             */
/*   Updated: 2022/07/06 13:35:39 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

t_data	g_server_data;

void	handler_get_message(int sig, siginfo_t *siginfo, void *useless)
{
	static int	bit = 8;
	static char	binary = '\0';

	(void)useless;
	if (sig == SIGUSR1 || sig == SIGUSR2)
		bit--;
	if (sig == SIGUSR1)
		binary += 1 << bit;
	if (bit == 0)
	{
		if (binary != '\0')
			g_server_data.msg = ft_str_charjoin(g_server_data.msg, binary);
		else
		{
			ft_putstr_fd(g_server_data.msg, 1);
			ft_putstr_fd("\n", 1);
			free(g_server_data.msg);
			g_server_sigaction.sa_sigaction = handler_start_connect;
			sigaction(SIGUSR1, &g_server_sigaction, NULL);
			sigaction(SIGUSR2, &g_server_sigaction, NULL);
			send_sig(siginfo->si_pid, SIGUSR2);
		}
		bit = 8;
		binary = '\0';
	}
}

void	handler_start_connect(int sig, siginfo_t *siginfo, void *useless)
{
	(void)useless;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		ft_putnbr_fd(siginfo->si_pid, 1);
		ft_putstr_fd(" : ", 1);
		g_server_data.pid = siginfo->si_pid;
		g_server_data.msg = ft_strdup("");
		g_server_sigaction.sa_sigaction = handler_get_message;
		sigaction(SIGUSR1, &g_server_sigaction, NULL);
		sigaction(SIGUSR2, &g_server_sigaction, NULL);
		send_sig(g_server_data.pid, sig);
	}
	else
		print_error("Connection Failed");
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		print_error("./server");
	sigemptyset(&g_server_sigaction.sa_mask);
	g_server_sigaction.sa_flags = SA_SIGINFO;
	g_server_sigaction.sa_sigaction = handler_start_connect;
	sigaction(SIGUSR1, &g_server_sigaction, NULL);
	sigaction(SIGUSR2, &g_server_sigaction, NULL);
	print_pid("Server");
	while (1)
		pause();
}

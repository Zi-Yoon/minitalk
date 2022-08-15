/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:48:59 by byan              #+#    #+#             */
/*   Updated: 2022/07/06 13:34:56 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

t_data	g_client_data;

void	handler_check_connect(int sig, siginfo_t *siginfo, void *useless)
{
	(void)siginfo;
	(void)useless;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Connection Successful\n", 1);
		g_client_sigaction.sa_sigaction = hdr_send_message;
		sigaction(SIGUSR1, &g_client_sigaction, NULL);
		sigaction(SIGUSR2, &g_client_sigaction, NULL);
		send_bit_message();
	}
	else if (sig == SIGUSR2)
		print_error("Connection Failed");
	else
		print_error("Wrong Signal");
}

void	hdr_send_message(int sig, siginfo_t *siginfo, void *useless)
{
	(void)siginfo;
	(void)useless;
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("Send message to server Successful\n", 1);
		exit(0);
	}
	else
		print_error("Failed to send message");
}

void	send_bit_message(void)
{
	static int	i = 0;
	static int	bit = 8;

	while (g_client_data.msg[i] != '\0')
	{
		while (--bit >= 0)
		{
			if ((g_client_data.msg[i] >> bit) & 1)
				send_sig(g_client_data.pid, SIGUSR1);
			else
				send_sig(g_client_data.pid, SIGUSR2);
		}
		bit = 8;
		i++;
	}
	if (g_client_data.msg[i] == '\0')
	{
		while (bit-- > 0)
			send_sig(g_client_data.pid, SIGUSR2);
		pause();
	}
}

void	connection_with_server(int sig)
{
	send_sig(g_client_data.pid, sig);
	pause();
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		print_error("./client [server_pid] [message]");
	g_client_sigaction.sa_flags = SA_SIGINFO;
	g_client_sigaction.sa_sigaction = handler_check_connect;
	sigemptyset(&g_client_sigaction.sa_mask);
	sigaction(SIGUSR1, &g_client_sigaction, NULL);
	sigaction(SIGUSR2, &g_client_sigaction, NULL);
	g_client_data.pid = ft_atoi(argv[1]);
	g_client_data.msg = argv[2];
	print_pid("Client");
	connection_with_server(SIGUSR1);
	return (0);
}

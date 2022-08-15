/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:53:15 by byan              #+#    #+#             */
/*   Updated: 2022/07/06 13:43:36 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include "../libft/libft.h"
# include <signal.h>

struct sigaction	g_client_sigaction;

typedef struct s_data
{
	pid_t			pid;
	char			*msg;
}			t_data;

void	send_sig(pid_t pid, int sig);
void	print_error(char *message);
void	print_pid(char *user);
void	handler_check_connect(int sig, siginfo_t *siginfo, void *useless);
void	hdr_send_message(int sig, siginfo_t *siginfo, void *useless);
void	send_bit_message(void);

#endif
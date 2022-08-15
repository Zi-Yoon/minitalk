/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:53:15 by byan              #+#    #+#             */
/*   Updated: 2022/07/02 09:53:05 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/libft.h"
# include <signal.h>

struct sigaction	g_server_sigaction;

typedef struct s_data
{
	pid_t			pid;
	char			*msg;
}			t_data;

void	send_sig(pid_t pid, int sig);
void	print_error(char *message);
void	print_pid(char *user);
char	*ft_str_charjoin(char *s1, char s2);

void	handler_get_message(int sig, siginfo_t *siginfo, void *useless);
void	handler_start_connect(int sig, siginfo_t *siginfo, void *useless);
#endif
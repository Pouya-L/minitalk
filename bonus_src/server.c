/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:38:09 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/21 17:56:40 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// void	config_signals()
// {
// 	signal(SIGUSR1, handler);
// 	signal(SIGUSR2, handler);
// }

void	handler(int	signum)
{
	static int	pos = 0;
	static char c;

	if (signum == SIGUSR1)
		c |= (0b1 << pos);
	pos++;
	if (pos == 8)
	{
		write(1, &c, 1);
		pos = 0;
		c = 0;
	}
}

void	send_feedback_signal(int signum, siginfo_t *info)
{
	(void)signum;
	kill(info->si_pid, SIGUSR1);
	ft_printf("\n");
}

void	sigaction_handler(int signum, siginfo_t *info, void *context)
{
	static int	pos = 0;
	static char c;

	(void)context;
	if (signum == SIGUSR1)
		c |= (0b1 << pos);
	pos++;
	if (pos == 8)
	{
		if (c == 0)
			send_feedback_signal(signum, info);
		write(1, &c, 1);
		pos = 0;
		c = 0;
	}
}

void	ft_display_banner(int pid)
{
	ft_printf("\t%s╔════════════════════════════════════════╗%s\n",\
	PURPLE, DEFAULT);
	ft_printf("\t%s║                                        ║%s\n",\
	PURPLE, DEFAULT);
	ft_printf("\t%s║          Welcome to minitalk,          ║%s\n",\
	PURPLE, DEFAULT);
	ft_printf("\t%s║            Server launched.            ║%s\n",\
	PURPLE, DEFAULT);
	ft_printf("\t%s║                                        ║%s\n",\
	PURPLE, DEFAULT);
	ft_printf("\t%s║      Use SERVER ID after ./client      ║%s\n",\
	PURPLE, DEFAULT);
	ft_printf("\t%s║      and then input your message.      ║%s\n",\
	PURPLE, DEFAULT);
	ft_printf("\t%s║                                        ║%s\n",\
	PURPLE, DEFAULT);
	ft_printf("\t%s║ %s    Made From 100%% Recycled Pixels    %s ║%s\n",\
	PURPLE, RED, PURPLE, DEFAULT);
	ft_printf("\t%s║                                        ║%s\n",\
	PURPLE, DEFAULT);
	ft_printf("\t%s╚════════════════════════════════════════╝%s\n",\
	PURPLE, DEFAULT);
	ft_printf("%s\t SERVER ID: %d%s            %sBy: plashkar%s\n\n",\
	CYAN, pid, DEFAULT, GREEN, DEFAULT);
}


int	main(void)
{
	struct sigaction sa;
	int	server_pid;

	sa.sa_sigaction = sigaction_handler;
	sa.sa_flags = SA_SIGINFO;
	server_pid = getpid();
	ft_display_banner(server_pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

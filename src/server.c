/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:38:09 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/21 16:05:20 by plashkar         ###   ########.fr       */
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
	ft_printf("\t%s║ %sNot a Substitute for Human Interaction%s ║%s\n",\
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
	int	server_pid;

	server_pid = getpid();
	ft_display_banner(server_pid);
	// config_signals();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}

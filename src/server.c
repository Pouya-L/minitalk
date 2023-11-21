/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:38:09 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/18 14:16:00 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sig_handler(int signum, siginfo_t *info, void *context)
{

}

int	main(void)
{
	struct sigaction	sa_new;

	ft_printf("%sServer launched.%s\n", PURPLE, DEFAULT);
	ft_printf("Server pid is: %s%d%s\n", PURPLE, getpid(), DEFAULT);
	sigemptyset(&sa_new.sa_mask);
	sa_new.sa_flags = SA_RESTART | SA_SIGINFO;
	sa_new.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa_new, NULL);
	sigaction(SIGUSR2, &sa_new, NULL);
	while(1)
		usleep(WAIT_TIME);
	return (0);
}

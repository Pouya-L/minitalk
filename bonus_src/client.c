/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:10:16 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/21 17:10:24 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_check_args_minitalk(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("%sInvalid number of arguments%s\n", RED, DEFAULT);
		return (0);
	}
	if (argc == 3)
	{
		pid = ft_atol(argv[1]);
		i = 0;
		while (argv[1][i])
		{
			if (!ft_isdigit(argv[1][i]) || pid > 4194304 || pid <= 0)
			{
				ft_printf("%sInvalid pid%s\n", RED, DEFAULT);
				return (0);
			}
			i++;
		}
	}
	return (1);
}

void	ft_send_bits(int pid, char c, int sleep_time)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((((c >> bit)) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(sleep_time);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int sleep_time;
	int	message_len;

	if (!ft_check_args_minitalk(argc, argv))
		return (0);
	pid = ft_atol(argv[1]);
	i = 0;
	message_len = ft_strlen(argv[2]);
	if (message_len <= 100)
		sleep_time = SHORT_SLEEP_TIME;
	else if (message_len <= 1000)
		sleep_time = MEDIUM_SLEEP_TIME;
	else
		sleep_time = LONG_SLEEP_TIME;
	while (argv[2][i])
	{
		ft_send_bits(pid, argv[2][i], sleep_time);
		i++;
	}
	return (0);
}

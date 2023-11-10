/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:22:12 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/10 16:07:42 by plashkar         ###   ########.fr       */
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
		pid = ft_atoi(argv[1]);
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
	return(1);
}

void	ft_send_bits(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((((c >> bit)) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
	}
	usleep(WAIT_TIME);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (!ft_check_args_minitalk(argc, argv))
		return (0);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_send_bits(pid, argv[2][i]);
		i++;
	}
	ft_send_bits(pid, '\n');
	return (0);
}



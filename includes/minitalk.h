/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:09:41 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/21 17:50:27 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H


# include "../libft/libft.h"
# include <signal.h>

# define _GNU_SOURCE

//Color codes for ft_printf
# define DEFAULT "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# define SHORT_SLEEP_TIME 100
# define MEDIUM_SLEEP_TIME 500
# define LONG_SLEEP_TIME 1000

int		ft_check_args_minitalk(int argc, char **argv);
void	ft_send_bits(int pid, char c, int sleep_time);
void	handler(int	signum);
void	ft_display_banner(int pid);

#endif

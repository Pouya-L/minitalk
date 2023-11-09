/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:09:41 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/09 20:12:24 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>

# define WAIT_TIME 100

int		ft_check_args_minitalk(int argc, char **argv);
void	ft_send_bits(int pid, char c);


#endif

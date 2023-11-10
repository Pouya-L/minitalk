/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:36:22 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/10 15:55:33 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_overflow_err(const char *str)
{
	ft_printf("overflow warning for input:%s\n", str);
	ft_printf("ft_atol will return 0\n");
	return (0);
}

long	ft_atol(const char *str)
{
	int	sign;
	long	value;
	long	i;

	i = 0;
	value = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i++] == '-')
				sign = sign * -1;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (value > (LONG_MAX - (str[i] - '0')) / 10)
				return((long)ft_overflow_err(str));
			value = value * 10 + (str[i++] - '0');
		}
		break ;
	}
	return (value * sign);
}

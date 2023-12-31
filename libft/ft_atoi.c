/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:00:31 by plashkar          #+#    #+#             */
/*   Updated: 2023/11/10 15:36:10 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	value;
	int	i;

	i = 0;
	value = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = sign * -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			value = value * 10 + (str[i] - '0');
			i++;
		}
		break ;
	}
	return (value * sign);
}

/*#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	char *str = "  	 		-420b678";
	printf("the original atoi result is : %d\n", atoi(str));
	//printf("my atoi result is : %d\n", ft_atoi(str));
	return (0);
}*/

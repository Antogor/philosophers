/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:06:28 by agarzon-          #+#    #+#             */
/*   Updated: 2025/03/15 13:32:15 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int			l;
	long int	numb;
	long int	negative;

	l = 0;
	numb = 0;
	negative = 1;
	while (nptr[l] != '\0')
	{
		if (nptr[l] == '\t' || nptr[l] == '\n' || nptr[l] == ' '
			|| nptr[l] == '\v' || nptr[l] == '\f' || nptr[l] == '\r')
			l++;
		else
			break ;
	}
	if (nptr[l] == '-')
		negative = -1;
	if (nptr[l] == '-' || nptr[l] == '+')
		l++;
	while (nptr[l] != '\0' && nptr[l] >= '0' && nptr[l] <= '9')
	{
		numb = (numb * 10 + (nptr[l] - '0'));
		l++;
	}
	return (numb * negative);
}

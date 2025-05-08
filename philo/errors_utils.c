/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:54:54 by antogor           #+#    #+#             */
/*   Updated: 2025/05/08 12:35:48 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_exception(char *msg)
{
	printf("Error in %s\n", msg);
	return (1);
}

void	generic_exception(char *msg)
{
	printf("Error in %s\n", msg);
}

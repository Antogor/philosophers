/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:31:11 by antogor           #+#    #+#             */
/*   Updated: 2025/05/08 12:35:30 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up_philos(t_philo *philos)
{
	if (!philos)
		return ;
	free(philos);
}

void	clean_up_data(t_data *data)
{
	if (!data)
		return ;
	free(data);
}

void	clean_up(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_total)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].meal_mutex);
		i++;
	}
	free(data->forks);
	clean_up_philos(data->philos);
	pthread_mutex_destroy(&data->print_mutex);
	clean_up_data(data);
}

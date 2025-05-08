/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:31:43 by antogor           #+#    #+#             */
/*   Updated: 2025/05/08 16:49:45 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->philo_total)
		{
			pthread_mutex_lock(&data->philos[i].meal_mutex);
			if (get_time_ms() - data->philos[i].last_eat_time
				> data->time_to_die)
			{
				pthread_mutex_lock(&data->stop_mutex);
				data->stop = 1;
				pthread_mutex_unlock(&data->stop_mutex);
				print_status(&data->philos[i], "died");
				return (NULL);
			}
			pthread_mutex_unlock(&data->philos[i].meal_mutex);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

int	check_stop(t_philo *philo)
{
	int	stop;

	stop = 0;
	pthread_mutex_lock(&philo->data->stop_mutex);
	stop = philo->data->stop;
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (stop);
}

void	smart_sleep(long duration, t_philo *philo)
{
	long	start;

	start = get_time_ms();
	while (!check_stop(philo) && get_time_ms() - start < duration)
		usleep(100);
}

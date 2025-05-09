/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:47:52 by antogor           #+#    #+#             */
/*   Updated: 2025/05/09 10:23:00 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	data->start_time = get_time_ms();
	i = 0;
	while (i < data->philo_total)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&thread_execution, &data->philos[i]) != 0)
			return (philo_exception("Start: Failed to create philo thread"));
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, monitor, data) != 0)
		return (philo_exception("Start: Failed to create monitor thread"));
	pthread_detach(monitor_thread);
	return (0);
}

void	end(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_total)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	execute(t_data *data)
{
	int	result;

	result = start(data);
	if (result)
		return (result);
	end(data);
	return (result);
}

void	*thread_execution(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	philo->last_eat_time = get_time_ms();
	if (philo->data->philo_total == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		smart_sleep(philo->data->time_to_die, philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(&philo->data->stop_mutex);
		philo->data->stop = 1;
		pthread_mutex_unlock(&philo->data->stop_mutex);
		print_status(philo, "died");
		return (NULL);
	}
	while (!check_stop(philo) && !philo_is_full(philo))
		party_time(philo);
	return (NULL);
}

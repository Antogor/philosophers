/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:47:52 by antogor           #+#    #+#             */
/*   Updated: 2025/04/07 17:51:00 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int		start(t_data *data)
{
    int i;

	data->start_time = get_time_ms();
    i = 0;
    while (i < data->philo_total)
    {
        if (pthread_create(&data->philos[i].thread, NULL, &thread_execution, &data->philos[i]) != 0)
			return philo_exception("Start: Failed to create philo thread");
        i++;
    }
	return (0);
}

void	end(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_total)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}
int		execute(t_data *data)
{
	int result;

    result = start(data);
	if (result)
		return (result);
	end(data);
    return (result);
}
void	*thread_execution(void *args)
{
    t_philo *philo;

    philo = (t_philo *)args;
    while (1)
    {
        pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
        print_status(philo, "is eating");
		philo->last_eat_time = get_time_ms();
        usleep(philo->data->time_to_eat * 1000);
		philo->eated++;
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        print_status(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
		print_status(philo, "is thinking");
    }

    return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:06:28 by agarzon-          #+#    #+#             */
/*   Updated: 2025/05/09 10:32:12 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d %s\n", get_time_ms() - philo->data->start_time,
		philo->philo_num, status);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	philo_is_dead(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->meal_mutex);
	time = get_time_ms() - philo->last_eat_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (time > philo->data->time_to_die)
		return (1);
	return (0);
}

int	philo_is_full(t_philo *philo)
{
	int	full;

	full = 0;
	if (philo->data->max_eat == 0)
		return (0);
	pthread_mutex_lock(&philo->meal_mutex);
	full = (philo->eated >= philo->data->max_eat);
	pthread_mutex_unlock(&philo->meal_mutex);
	return (full);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:52:04 by antogor           #+#    #+#             */
/*   Updated: 2025/05/08 11:39:49 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	party_time(t_philo	*philo)
{
	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_eat_time = get_time_ms();
	pthread_mutex_unlock(&philo->meal_mutex);
	smart_sleep(philo->data->time_to_eat, philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->eated++;
	pthread_mutex_unlock(&philo->meal_mutex);
	end_party_time(philo);
}

void	end_party_time(t_philo *philo)
{
	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	print_status(philo, "is sleeping");
	smart_sleep(philo->data->time_to_sleep, philo);
	print_status(philo, "is thinking");
}

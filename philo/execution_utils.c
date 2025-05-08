/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:52:04 by antogor           #+#    #+#             */
/*   Updated: 2025/05/08 16:44:42 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	party_time(t_philo	*philo)
{
	if (check_stop(philo))
		return ;
	lunch_party_time(philo);
	if (check_stop(philo))
		return ;
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_eat_time = get_time_ms();
	philo->eated++;
	pthread_mutex_unlock(&philo->meal_mutex);
	smart_sleep(philo->data->time_to_eat, philo);
	end_party_time(philo);
}

void	lunch_party_time(t_philo *philo)
{
	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		if (check_stop(philo))
		{
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		if (check_stop(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			return ;
		}
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (check_stop(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			return ;
		}
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		if (check_stop(philo))
		{
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
		print_status(philo, "has taken a fork");
	}
}

void	end_party_time(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (check_stop(philo))
		return ;
	print_status(philo, "is sleeping");
	smart_sleep(philo->data->time_to_sleep, philo);
	if (check_stop(philo))
		return ;
	print_status(philo, "is thinking");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:15:55 by antogor           #+#    #+#             */
/*   Updated: 2025/04/07 18:02:21 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_up_forks(t_data *data)
{
    int	i;

    data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_total);
    if (!data->forks)
        generic_exception("Set_up: Failed to allocate fork memory");
    i = 0;
    while (i < data->philo_total)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
            generic_exception("Set_up: Failed to initialize fork mutex");
        i++;
    }
    if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
            generic_exception("Set_up: Failed to initialize print fork mutex");
}

void	set_up_philos(t_data *data)
{
    int	i;

    data->philos = malloc(sizeof(t_philo) * data->philo_total);
    if (!data->philos)
        generic_exception("Set_up: Failed to allocate philo memory");
    i = 0;
    while (i < data->philo_total)
    {
        data->philos[i].data = data;
        data->philos[i].philo_num = i + 1;
        data->philos[i].eated = 0;
        data->philos[i].last_eat_time = 0;
        data->philos[i].left_fork = &data->forks[i];
        data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_total];
        i++;
    }
}

t_data  *set_up_data(int argc, char **argv)
{
    t_data  *data;

    data = malloc(sizeof(t_data));
    if (!data)
        generic_exception("Set_up: Failed to allocate data memory");
    data->philo_total = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->max_eat = 0;
    if (argc == 6)
        data->max_eat = ft_atoi(argv[5]);
    return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:31:11 by antogor           #+#    #+#             */
/*   Updated: 2025/04/07 17:40:05 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    clean_up_philos(t_philo *philos)
{
    if (!philos)
        return ;
    free(philos);
}
void    clean_up_data(t_data *data)
{
    if (!data)
        return ;
    free(data);
}
void    clean_up(t_data *data)
{
    clean_up_philos(data->philos);
    if(!data->forks)
        return ;
    free(data->forks);
    clean_up_data(data);
}

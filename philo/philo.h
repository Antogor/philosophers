/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:32:32 by agarzon-          #+#    #+#             */
/*   Updated: 2025/03/15 14:25:13 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>

typedef struct t_philo
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			eated;
	int			philo_num;
	pthread_t	*thread;
}	t_philo;

int	ft_atoi(const char *nptr);

#endif

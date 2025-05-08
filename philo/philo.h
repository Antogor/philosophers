/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:15:55 by agarzon-          #+#    #+#             */
/*   Updated: 2025/05/08 16:34:33 by antogor          ###   ########.fr       */
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

typedef struct s_data	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				philo_num;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	int				eated;
	long			last_eat_time;
}					t_philo;

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				philo_total;
	long			start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	int				stop;
	pthread_mutex_t	stop_mutex;
	t_philo			*philos;
}					t_data;

// Execute
void				*thread_execution(void *args);
int					execute(t_data *data);
int					start(t_data *data);
void				end(t_data *data);

// Utils
int					ft_atoi(const char *nptr);
long				get_time_ms(void);
void				print_status(t_philo *philo, char *status);
int					philo_is_dead(t_philo *philo);
int					philo_is_full(t_philo *philo);
void				*monitor(void *arg);
void				smart_sleep(long duration, t_philo *philo);
void				party_time(t_philo	*philo);
void				lunch_party_time(t_philo *philo);
void				end_party_time(t_philo *philo);
int					check_stop(t_philo *philo);

// Set Up
t_data				*set_up_data(int argc, char **argv);
void				set_up_philos(t_data *data);
void				set_up_forks(t_data *data);

// Clean Up
void				clean_up(t_data *data);
void				clean_up_data(t_data *data);
void				clean_up_philos(t_philo *philos);

// Exceptions
int					philo_exception(char *msg);
void				generic_exception(char *msg);

#endif

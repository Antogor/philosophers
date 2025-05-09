/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antogor <antogor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:08:33 by agarzon-          #+#    #+#             */
/*   Updated: 2025/05/09 10:38:20 by antogor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		result;

	data = NULL;
	result = 0;
	if (argc > 6 || argc < 5)
		return (philo_exception("Main: Invalid number of arguments"));
	if (!check_arguments(argc, argv))
		return (philo_exception("Main: Invalid arguments"));
	data = set_up_data(argc, argv);
	if (!data)
		return (philo_exception("Main: Failed creating data"));
	set_up_forks(data);
	if (!data->forks)
		return (philo_exception("Main: Failed creating forks"));
	set_up_philos(data);
	if (!data->philos)
		return (philo_exception("Main: Failed creating philos"));
	result = execute(data);
	clean_up(data);
	return (result);
}

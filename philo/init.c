/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:45:53 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/29 03:26:20 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
        sleeping(philo);
        thinking(philo);
        usleep(10000);
    printf("Philo\n");
	return (NULL);
}

int	init_philos(t_philo *philos, t_fork *forks, t_info *info)
{
	int	id;

	id = -1;
	while (++id < info->philo_number)
	{
		philos[id].id = id + 1;
		philos[id].meals_eaten = 0;
		philos[id].state = 0;
		if (pthread_create(&philos[id].thread, NULL, &philo_life,
				&philos[id]) != 0)
			return (-1);
        printf("rah sala creation\n");
		pthread_join(philos[id].thread, NULL);
		if (id % 2 == 0)
		{
			philos[id].first_fork = &forks[id];
			philos[id].second_fork = &forks[info->philo_number - id];
		}
		else
		{
			philos[id].first_fork = &forks[info->philo_number - id];
			philos[id].second_fork = &forks[id];
		}
        printf("Philo n = %d finished\n", philos[id].id);
	}
	return (0);
}

int	init_forks(t_fork *forks, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_number)
	{
		forks[i].fork_id = i + 1;
		if (safe_mutex(&forks[i].fork, 0) != 0)
			return (-1);
	}
	return (0);
}

int	init_data(t_info *info, t_philo *philos, t_fork *forks)
{
	int	i;

	i = -1;
	if (init_forks(forks, info) != 0)
		return (-1);
	if (init_philos(philos, forks, info) != 0)
		return (-1);
	printf("init is finished\n");
	return (0);
}

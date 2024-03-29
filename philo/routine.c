/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 03:00:12 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/29 03:21:04 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	eating()
// {
	
// }

void	sleeping(t_philo *philo)
{
	printf("%d %d is sleeping\n", 1, philo->id);
	printf("time => %ld\n", philo->info->time_to_sleep);
	usleep(5);
	printf("cc\n");
}

void	thinking(t_philo *philo)
{
	printf("%d %d is thinking\n", 1,philo->id);
}

// void	routine(t_philo *philo)
// {
	
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 03:00:12 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/29 04:16:34 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	// eating process;
	philo->time_to_start = get_time();
	philo->last_meal_time = get_time();
}

void	sleeping(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_time() - philo->time_to_start, philo->id);
	usleep(philo->time_to_sleep * 1e3);
}

void	thinking(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_time() - philo->time_to_start, philo->id);
}

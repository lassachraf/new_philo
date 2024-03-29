/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:36:42 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/29 02:59:17 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	parsing(t_info *info, char **av)
{
	info->philo_number = ft_atol(av[1]);
	if (info->philo_number == 0 || info->philo_number == -1337)
	{
		ft_error("Input error !");
		return (false);
	}
	info->time_to_die = ft_atol(av[2]);
	info->time_to_eat = ft_atol(av[3]);
	info->time_to_sleep = ft_atol(av[4]);
	info->max_meals = ft_atol(av[5]);
	printf("max meals: %d\n", info->max_meals);
	return (true);
}

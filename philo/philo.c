/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:35:36 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/29 03:20:10 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	philos[PHILO_MAX];
	t_fork	forks[PHILO_MAX];

	if (ac == 5 || ac == 6)
	{
		if (!parsing(&info, av))
			return (0);
		printf("Done parsing\n");
		philos->info = &info;
		if (init_data(&info, philos, forks) != 0)
			return (0);
	}
	else
		arg_error();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:40:56 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/29 02:46:48 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	safe_mutex(pthread_mutex_t *mutex, int flag)
{
	if (flag == 0)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			return (-1);
	}
	else if (flag == 1)
	{
		if (pthread_mutex_lock(mutex) != 0)
			return (-1);
	}
	else if (flag == 2)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			return (-1);
	}
	else if (flag == 3)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			return (-1);
	}
	return (0);
}

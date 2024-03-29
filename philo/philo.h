/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:40:34 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/29 03:21:23 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef PHILO_MAX
#  define PHILO_MAX 300
# endif

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_info	t_info;

typedef struct s_locks
{
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
	pthread_mutex_t		*write_lock;
}						t_locks;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	int					state;
	pthread_t			thread;
	t_info				*info;
	t_fork				*first_fork;
	t_fork				*second_fork;
	t_locks				locks;
}						t_philo;

typedef struct s_info
{
	int					philo_number;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					max_meals;
}						t_info;

// Utils functions :
long					ft_atol(char *str);

// Parsing functions :
bool					parsing(t_info *info, char **av);

// Init function :
int						init_data(t_info *info, t_philo *philos, t_fork *forks);

// Safe functions :
int						safe_mutex(pthread_mutex_t *mutex, int flag);

// Free functions :
void					free_and_cleanup(t_info *info);

// Actions functions :
// void                    eat(t_philo *philo);
void                    sleeping(t_philo *philo);
void                    thinking(t_philo *philo);
// void                    die(t_philo *philo);
// void                    meals(t_philo *philo);

// Main function :

// Error functions :
void					arg_error(void);
void					ft_error(char *s);
void					thread_errors(int status);

#endif
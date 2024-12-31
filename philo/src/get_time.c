/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:02:32 by hkheired          #+#    #+#             */
/*   Updated: 2024/10/14 13:38:26 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

long	ft_get_start_time(t_data *data)
{
	long	time;

	pthread_mutex_lock(&data->start_time_mt);
	time = data->start_time;
	pthread_mutex_unlock(&data->start_time_mt);
	return (time);
}

long	ft_get_eat_time(t_data *data)
{
	long	time;

	pthread_mutex_lock(&data->eat_mt);
	time = data->eat_time;
	pthread_mutex_unlock(&data->eat_mt);
	return (time);
}

long	ft_get_sleep_time(t_data *data)
{
	long	time;

	pthread_mutex_lock(&data->sleep_mt);
	time = data->sleep_time;
	pthread_mutex_unlock(&data->sleep_mt);
	return (time);
}

long	ft_get_die_time(t_data *data)
{
	long	time;

	pthread_mutex_lock(&data->die_mt);
	time = data->die_time;
	pthread_mutex_unlock(&data->die_mt);
	return (time);
}

long	ft_get_last_eat_time(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->last_eat_time_m);
	time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->last_eat_time_m);
	return (time);
}

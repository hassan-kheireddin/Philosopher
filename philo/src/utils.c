/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:41:19 by hkheired          #+#    #+#             */
/*   Updated: 2024/12/31 14:39:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	ft_free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = ft_get_nb_philo(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].state_m);
		pthread_mutex_destroy(&data->philos[i].last_eat_time_m);
		pthread_mutex_destroy(&data->philos[i].nb_meals_had_m);
	}
	pthread_mutex_destroy(&data->eat_mt);
	pthread_mutex_destroy(&data->die_mt);
	pthread_mutex_destroy(&data->sleep_mt);
	pthread_mutex_destroy(&data->print_mt);
	pthread_mutex_destroy(&data->nb_philos_mt);
	pthread_mutex_destroy(&data->keep_iter_mt);
	pthread_mutex_destroy(&data->start_time_mt);
	free(data->philo_ths);
	free(data->forks);
	free(data->philos);
}

void	ft_printmsg(t_data *data, int id, char *msg)
{
	long	time;

	time = ft_get_time() - ft_get_start_time(data);
	pthread_mutex_lock(&data->print_mt);
	if (ft_keep_iter(data))
		printf("%ld %d %s \n", time, id, msg);
	pthread_mutex_unlock(&data->print_mt);
}

int	ft_meals_nb(t_data *data)
{
	if (data->nb_meals > 0)
		return (1);
	return (0);
}

int	ft_handle_one_philo(t_philo *philo)
{
	ft_take_left_fork(philo);
	ft_drop_left_fork(philo);
	ft_usleep(ft_get_die_time(philo->data));
	ft_set_philo_state(philo, DEAD);
	return (1);
}

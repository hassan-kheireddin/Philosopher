/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:21:26 by hkheired          #+#    #+#             */
/*   Updated: 2024/10/29 10:53:54 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	ft_get_nb_philo(t_data *data)
{
	int	philo_nb;

	pthread_mutex_lock(&data->nb_philos_mt);
	philo_nb = data->nb_philos;
	pthread_mutex_unlock(&data->nb_philos_mt);
	return (philo_nb);
}

int	ft_get_nb_meals_had(t_philo *philo)
{
	int	nb;

	pthread_mutex_lock(&philo->nb_meals_had_m);
	nb = philo->nb_meals_had;
	pthread_mutex_unlock(&philo->nb_meals_had_m);
	return (nb);
}

t_philo_state	ft_get_philo_state(t_philo *philo)
{
	t_philo_state	state;

	pthread_mutex_lock(&philo->state_m);
	state = philo->state;
	pthread_mutex_unlock(&philo->state_m);
	return (state);
}

int	ft_keep_iter(t_data *data)
{
	int		bol;

	pthread_mutex_lock(&data->keep_iter_mt);
	bol = data->keep_iter;
	pthread_mutex_unlock(&data->keep_iter_mt);
	return (bol);
}

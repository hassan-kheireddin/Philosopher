/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:07:46 by hkheired          #+#    #+#             */
/*   Updated: 2024/10/29 10:54:10 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/philosopher.h"

void	ft_set_keep_iterating(t_data *data, int set_to)
{
	pthread_mutex_lock(&data->keep_iter_mt);
	data->keep_iter = set_to;
	pthread_mutex_unlock(&data->keep_iter_mt);
}

void	ft_set_philo_state(t_philo *philo, t_philo_state state)
{
	pthread_mutex_lock(&philo->state_m);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->state_m);
}

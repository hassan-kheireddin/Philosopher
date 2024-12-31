/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:25:07 by hkheired          #+#    #+#             */
/*   Updated: 2024/12/31 15:26:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/philosopher.h"

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_mf);
	pthread_mutex_unlock(philo->right_mf);
}

void	ft_update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eat_time_m);
	philo->last_eat_time = ft_get_time();
	pthread_mutex_unlock(&philo->last_eat_time_m);
}

void	ft_update_nb_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo->nb_meals_had_m);
	philo->nb_meals_had++;
	pthread_mutex_unlock(&philo->nb_meals_had_m);
}

void	ft_sleep_for_eating(t_philo *philo)
{
	ft_usleep(ft_get_eat_time(philo->data));
}

int	ft_eat(t_philo *philo)
{
	if (ft_take_forks(philo) != 0)
		return (1);
	ft_set_philo_state(philo, EATING);
	ft_printmsg(philo->data, philo->id, "\033[0;35mis eating spaghetti \033[0m");
	ft_update_last_meal_time(philo);
	ft_update_nb_meals_had(philo);
	ft_sleep_for_eating(philo);
	ft_drop_forks(philo);
	return (0);
}

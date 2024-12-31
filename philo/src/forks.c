/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:17:25 by hkheired          #+#    #+#             */
/*   Updated: 2024/12/31 14:44:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/philosopher.h"

void	ft_drop_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_mf);
}

void	ft_drop_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_mf);
}

int	ft_take_left_fork(t_philo *philo)
{
	if (ft_philo_died(philo) || ft_get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->left_mf);
	ft_printmsg(philo->data, philo->id, "\033[0;32mhas taken a fork \033[0m");
	return (0);
}

int	ft_take_right_fork(t_philo *philo)
{
	if (ft_philo_died(philo) || ft_get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->right_mf);
	ft_printmsg(philo->data, philo->id, "\033[0;32mhas taken a fork \033[0m");
	return (0);
}

int	ft_take_forks(t_philo *philo)
{
	if (ft_get_nb_philo(philo->data) == 1)
		return (ft_handle_one_philo(philo));
	if (philo->id % 2 == 0)
	{
		if (ft_take_right_fork(philo) != 0)
			return (1);
		if (ft_take_left_fork(philo) != 0)
		{
			ft_drop_right_fork(philo);
			return (1);
		}
	}
	else
	{
		if (ft_take_left_fork(philo) != 0)
			return (1);
		if (ft_take_right_fork(philo) != 0)
		{
			ft_drop_left_fork(philo);
			return (1);
		}
	}
	return (0);
}

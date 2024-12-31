/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:12:58 by hkheired          #+#    #+#             */
/*   Updated: 2024/10/29 10:36:26 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/philosopher.h"

void	*ft_routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	ft_update_last_meal_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (ft_get_philo_state(philo) != DEAD)
	{
		if (ft_eat(philo) != 0)
			break ;
		if (ft_get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (ft_get_philo_state(philo) == DEAD)
			break ;
		if (ft_think(philo) != 0)
			break ;
	}
	return (NULL);
}

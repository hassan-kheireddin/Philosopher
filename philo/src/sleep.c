/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:40:29 by hkheired          #+#    #+#             */
/*   Updated: 2024/12/31 14:51:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/philosopher.h"

int	ft_sleep(t_philo *philo)
{
	ft_set_philo_state(philo, SLEEPING);
	if (ft_get_philo_state(philo) == DEAD)
		return (1);
	ft_printmsg(philo->data, philo->id, "\033[0;34mis sleeping \033[0m");
	ft_usleep(ft_get_sleep_time(philo->data));
	return (0);
}

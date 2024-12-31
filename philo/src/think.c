/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:05:19 by hkheired          #+#    #+#             */
/*   Updated: 2024/12/31 14:52:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/philosopher.h"

int	ft_think(t_philo *philo)
{
	ft_set_philo_state(philo, THINKING);
	if (ft_get_philo_state(philo) == DEAD)
		return (1);
	ft_printmsg(philo->data, philo->id, "\033[0;31mis thinking\033[0m");
	return (0);
}

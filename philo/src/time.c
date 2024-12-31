/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:09:40 by hkheired          #+#    #+#             */
/*   Updated: 2024/10/29 10:34:42 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/philosopher.h"

void	ft_usleep(long sleep_time)
{
	long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < sleep_time)
		usleep(500);
}

long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (long)1000) + (tv.tv_usec / 1000));
}

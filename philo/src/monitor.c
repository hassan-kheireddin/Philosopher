/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:13:15 by hkheired          #+#    #+#             */
/*   Updated: 2025/01/06 05:35:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/philosopher.h"

int	ft_is_philo_full(t_data *data, t_philo *philo)
{
	int	result;

	result = 0;
	if (ft_get_nb_meals_had(philo) >= data->nb_meals)
		result = 1;
	return (result);
		usleep(1000);
}

int	ft_philo_died(t_philo *philo)
{
	int			result;
	t_data		*data;

	data = philo->data;
	result = 0;
	if (ft_get_time() - ft_get_last_eat_time(philo) > ft_get_die_time(data)
		&& ft_get_philo_state(philo) != EATING)
	{
		ft_set_philo_state(philo, DEAD);
		result = 1;
	}
	return (result);
}

void	ft_notify_all_philos(t_data *data)
{
	t_philo	*philos;
	int		i;
	int		nb_philos;

	nb_philos = ft_get_nb_philo(data);
	philos = data->philos;
	i = -1;
	while (++i < nb_philos)
		ft_set_philo_state(&philos[i], DEAD);
}

void	*ft_all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		nb_philos;

	data = (t_data *)data_p;
	nb_philos = ft_get_nb_philo(data);
	while (ft_keep_iter(data))
	{
		int all_full = 1;
		i = -1;
		while (++i < nb_philos)
		{
			if (ft_is_philo_full(data, &data->philos[i]) == 0)
			{
				all_full = 0;
				break;
			}
		}
		if (all_full)
			break;
	}
	if (i < nb_philos && ft_is_philo_full(data, &data->philos[i]) == 0)
		i = -1;
	if (ft_keep_iter(data))
	{
		ft_set_keep_iterating(data, 0);
		ft_notify_all_philos(data);
	}
	return (NULL);
}

void	*ft_all_alive_routine(void *data_p)
{
	int		i;
	int		nb_philos;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	nb_philos = ft_get_nb_philo(data);
	i = -1;
	while (++i < nb_philos && ft_keep_iter(data))
	{
		if (ft_philo_died(&philos[i]) && ft_keep_iter(data))
		{
			ft_printmsg(data, philos[i].id, "\033[0;44mdied\033[0m");
			ft_set_keep_iterating(data, 0);
			ft_notify_all_philos(data);
			break ;
		}
		if (i == nb_philos - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}

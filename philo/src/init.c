/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:47:33 by hkheired          #+#    #+#             */
/*   Updated: 2024/12/31 14:21:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	ft_malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
		return (2);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
		return (free(data->philos), 2);
	data->philo_ths = malloc(sizeof(pthread_t) * data->nb_philos);
	if (data->philo_ths == NULL)
		return (free(data->philos), free(data->forks), 2);
	return (0);
}

int	ft_int_data(t_data *data, int ac, char **av)
{
	data->nb_philos = ft_atoi(av[1]);
	data->die_time = (long)ft_atoi(av[2]);
	data->eat_time = (long)ft_atoi(av[3]);
	data->sleep_time = (long)ft_atoi(av[4]);
	data->nb_full_p = 0;
	data->keep_iter = 1;
	data->nb_meals = -1;
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
	if (data->nb_meals == 0)
	{
		ft_print_instruction();
		return(1);
	}
	pthread_mutex_init(&data->eat_mt, NULL);
	pthread_mutex_init(&data->sleep_mt, NULL);
	pthread_mutex_init(&data->die_mt, NULL);
	pthread_mutex_init(&data->print_mt, NULL);
	pthread_mutex_init(&data->nb_philos_mt, NULL);
	pthread_mutex_init(&data->keep_iter_mt, NULL);
	pthread_mutex_init(&data->start_time_mt, NULL);
	return (ft_malloc_data(data));
}

int	ft_init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = data->philos;
	while (++i < data->nb_philos)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].nb_meals_had = 0;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].state_m, NULL);
		pthread_mutex_init(&philos[i].nb_meals_had_m, NULL);
		pthread_mutex_init(&philos[i].last_eat_time_m, NULL);
		ft_update_last_meal_time(&philos[i]);
	}
	return (0);
}

int	ft_init_forks(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	philos[0].left_mf = &data->forks[0];
	philos[0].right_mf = &data->forks[data->nb_philos - 1];
	while (++i < data->nb_philos)
	{
		philos[i].left_mf = &data->forks[i];
		philos[i].right_mf = &data->forks[i - 1];
	}
	return (0);
}

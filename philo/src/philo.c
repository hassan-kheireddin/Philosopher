/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:20:10 by hkheired          #+#    #+#             */
/*   Updated: 2024/12/31 15:13:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/philosopher.h"

int	ft_run_threads(t_data *data)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = ft_get_nb_philo(data);
	i = 0;
	data->start_time = ft_get_time();
	while (i < nb_of_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
				&ft_routine, &data->philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&data->monit_all_alive, NULL,
			&ft_all_alive_routine, data))
		return (1);
	if (ft_meals_nb(data) == 1
		&& pthread_create(&data->monit_all_full, NULL,
			&ft_all_full_routine, data))
		return (1);
	return (0);
}

int	ft_join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = ft_get_nb_philo(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (ft_meals_nb(data) == 1
		&& pthread_join(data->monit_all_full, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

int	philosophers(int ac, char **av)
{
	t_data	data;

	if (ft_int_data(&data, ac, av) != 0)
		return (2);
	ft_init_philos(&data);
	ft_init_forks(&data);
	ft_run_threads(&data);
	ft_join_threads(&data);
	ft_free_data(&data);
	return (0);
}

void	ft_leaks(void)
{
	system("leaks philo");
}

int	main(int ac, char **av)
{
	if (ft_check_input(ac, av) != 0)
	{
		ft_print_instruction();
		return (1);
	}
	if (philosophers(ac, av) != 0)
		return (2);
	printf("\033[0;33mProgram End!\033[0m \n");
	return (0);
}

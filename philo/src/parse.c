/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 07:27:27 by hkheired          #+#    #+#             */
/*   Updated: 2024/12/31 14:11:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/philosopher.h"

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\r' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

int	ft_is_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_input(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (1);
	if (ft_is_digit(ac, av) != 0)
		return (1);
	if (ac == 6 && av[5] == 0)
		return (1);
	if (ft_atoi(av[1]) < 1)
		return (1);
	return (0);
}

void	ft_print_instruction(void)
{
	printf("\033[0;31m\n\t\tWRONG INPUT!\n\n");
	printf("\t./philo nb_philos time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("nb_meal\n");
	printf("Example:\n");
	printf("\t\t./philo 4 800 200 200 5 \n\033[0m");
}

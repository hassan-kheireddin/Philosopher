/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 07:28:35 by hkheired          #+#    #+#             */
/*   Updated: 2024/12/31 15:28:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H 

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_philo_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	long			last_eat_time;
	struct s_data	*data;
	t_philo_state	state;
	pthread_mutex_t	*left_mf;
	pthread_mutex_t	*right_mf;
	pthread_mutex_t	state_m;
	pthread_mutex_t	nb_meals_had_m;
	pthread_mutex_t	last_eat_time_m;
}t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_p;
	int				keep_iter;
	long			eat_time;
	long			die_time;
	long			sleep_time;
	long			start_time;
	pthread_mutex_t	eat_mt;
	pthread_mutex_t	die_mt;
	pthread_mutex_t	sleep_mt;
	pthread_mutex_t	print_mt;
	pthread_mutex_t	nb_philos_mt;
	pthread_mutex_t	keep_iter_mt;
	pthread_mutex_t	start_time_mt;
	pthread_mutex_t	*forks;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	t_philo			*philos;
}t_data;

t_philo_state	ft_get_philo_state(t_philo *philo);
void			ft_set_keep_iterating(t_data *data, int set_to);
void			ft_set_philo_state(t_philo *philo, t_philo_state state);
/////////////////////////////////////////////////////////////////

////////////////////////////eat.c////////////////////////////
void			ft_drop_forks(t_philo *philo);
void			ft_update_last_meal_time(t_philo *philo);
void			ft_update_nb_meals_had(t_philo *philo);
void			ft_sleep_for_eating(t_philo *philo);
int				ft_eat(t_philo *philo);
/////////////////////////////////////////////////////////////

////////////////////////////forks.c////////////////////////////
void			ft_drop_left_fork(t_philo *philo);
void			ft_drop_right_fork(t_philo *philo);
int				ft_take_left_fork(t_philo *philo);
int				ft_take_right_fork(t_philo *philo);
int				ft_take_forks(t_philo *philo);
///////////////////////////////////////////////////////////////

////////////////////////////get_numbers.c////////////////////////////
int				ft_get_nb_philo(t_data *data);
int				ft_get_nb_meals_had(t_philo *philo);
int				ft_keep_iter(t_data *data);
/////////////////////////////////////////////////////////////////////

////////////////////////////get_time.c////////////////////////////
long			ft_get_start_time(t_data *data);
long			ft_get_eat_time(t_data *data);
long			ft_get_sleep_time(t_data *data);
long			ft_get_die_time(t_data *data);
long			ft_get_last_eat_time(t_philo *philo);
//////////////////////////////////////////////////////////////////

////////////////////////////init.c////////////////////////////
int				ft_malloc_data(t_data *data);
int				ft_int_data(t_data *data, int ac, char **av);
int				ft_init_philos(t_data *data);
int				ft_init_forks(t_data *data);
//////////////////////////////////////////////////////////////

////////////////////////////loop.c////////////////////////////
void			*ft_routine(void *philo_p);
//////////////////////////////////////////////////////////////

////////////////////////////monitor.c////////////////////////////
int				ft_is_philo_full(t_data *data, t_philo *philo);
int				ft_philo_died(t_philo *philo);
void			ft_notify_all_philos(t_data *data);
void			*ft_all_full_routine(void *data_p);
void			*ft_all_alive_routine(void *data_p);
/////////////////////////////////////////////////////////////////

////////////////////////////parse.c////////////////////////////
int				ft_atoi(char *str);
int				ft_is_digit(int ac, char **av);
int				ft_wrong_input_check(int argc, char **argv);
int				ft_check_input(int ac, char **av);
void			ft_print_instruction(void);
///////////////////////////////////////////////////////////////

////////////////////////////philo.c////////////////////////////
int				ft_run_threads(t_data *data);
int				ft_join_threads(t_data *data);
int				philosophers(int ac, char **av);
void			ft_leaks(void);
int				main(int ac, char **av);
///////////////////////////////////////////////////////////////

////////////////////////////sleep.c////////////////////////////
int				ft_sleep(t_philo *philo);
///////////////////////////////////////////////////////////////

////////////////////////////think.c////////////////////////////
int				ft_think(t_philo *philo);
///////////////////////////////////////////////////////////////

////////////////////////////time.c////////////////////////////
void			ft_usleep(long sleep_time);
long			ft_get_time(void);
//////////////////////////////////////////////////////////////

////////////////////////////utils.c////////////////////////////
void			ft_free_data(t_data *data);
void			ft_printmsg(t_data *data, int id, char *msg);
int				ft_meals_nb(t_data *data);
int				ft_handle_one_philo(t_philo *philo);
////////////////////////////////////////////////////////////////



#endif

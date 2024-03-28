/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:49:12 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/28 15:14:48 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int  main(int argc, char **argv)
{
    data_t vars;

	memset(&vars, 0, sizeof(vars));
	init_values(&vars, argv, argc);
	init_philo(&vars);
    process_diner(&vars);
}

// pour que tout les philos est une fourchette utiliser (i + 1) % data->number_of_philosopher.fork_left

void    init_values(data_t *data, char **argv, int argc)
{
    int i;
    int y;

    i  = 0;
    y  = 1;
    
    data->number_of_philosophers =  ft_atoi(argv[1]);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
    while (y <= data->number_of_philosophers)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
        y++;
    }
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]) * 1000;
    data->time_to_sleep = ft_atoi(argv[4]) * 1000;
    data->all_ready = false;
    data->id_philo = malloc(sizeof(philo_t *) * data->number_of_philosophers);
    if (argc == 6)
        data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    else
        data->number_of_times_each_philosopher_must_eat = 0; //potentielemente inutile j'ai fais un memset
}

//initialiser la vie de chaque philo avec une boucle qui donne temps + temps de mort et a chaque fois qu'il mange remettre + temps de mort a life 
void    init_philo(data_t *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philosophers)
    {
        data->id_philo[i] = malloc(sizeof(philo_t));
        i++;
    }
    i = 0;
    while (i < data->number_of_philosophers)
    {
    
        data->id_philo[i]->life = data->time_to_die * 1000;
        data->id_philo[i]->fork_right = &(data->forks[i]);
        data->id_philo[i]->fork_left = &(data->forks[(i + 1) % data->number_of_philosophers]);
        data->id_philo[i]->number = i;
         data->id_philo[i]->all_ready = &data->all_ready;
        data->id_philo[i]->info = data;
        i++;
    } 
}

void    *my_thread_to_sleep(philo_t *philo)
{
    printf("Philosopher %d is sleeping\n", philo->number);
    philo->sleep = 1;
    usleep(philo->info->time_to_sleep);
    philo->sleep = 0;
    return (NULL);
}

void    *my_thread_to_take_forks(philo_t *philo)
{
    if (pthread_mutex_lock(philo->fork_left) != 0)
		return (NULL);
    printf("philosopher %d taken a fork left\n", philo->number);
    if (pthread_mutex_lock(philo->fork_right) != 0)
	{
		pthread_mutex_unlock(philo->fork_left);
		return (NULL);
	}
    printf("philosopher %d taken a fork right\n", philo->number);
	philo_eating(philo);
	return (NULL);
}

void	philo_eating(philo_t *philo)
{
	struct timeval new_time;
	long long milliseconds;

	gettimeofday(&new_time, NULL);
	milliseconds = get_current_milliseconds();
	printf("philosopher %d eating\n", philo->number);
	philo->hunger++;
	philo->life= milliseconds + philo->info->time_to_die;
	usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
    my_thread_to_sleep(philo);
    
}

void    *my_thread_to_think(philo_t *philo)
{
    usleep(50);
    printf("Philosopher %d is thinking\n", philo->number);
	return (NULL);
}

//idee faire une fonction qui regarde le temps de chaque philo et quand il mange remet a 0 mais par contre si il depasse alors dit qu'il est mort 

int    my_thread_to_die(philo_t *philo)
{
    int i;
    int	y;
	long long current_milliseconds;
	long long philo_life_milliseconds;

    i = 0;
	y = 0;

	current_milliseconds = get_current_milliseconds();
    while (y != philo->info->number_of_philosophers)
	{
    	while (i < philo->info->number_of_philosophers)
    	{
			philo_life_milliseconds = philo->info->id_philo[i]->life;
			if (philo_life_milliseconds < current_milliseconds) 
            {
				printf("Philosopher %d is dead\n", i);
                philo->info->dead = 1;
				return (-1);
			}
			i++;
    	}
		i = 0;
        y++;
	}
	return (0);
}

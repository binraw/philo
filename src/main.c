/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:49:12 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/25 13:53:43 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int  main(int argc, char **argv)
{
    data_t **vars;
    timeval_t time;
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    

	memset(&vars, 0, sizeof(vars));
	init_values(vars, argv);
	init_philo(&vars);


	
    
}

// pour que tout les philos est une fourchette utiliser (i + 1) % data->number_of_philosopher.fork_left

void    init_values(data_t *philo, char **argv)
{
    philo->number_of_philosophers =  ft_atoi(argv[1]);
    philo->time_to_die = ft_atoi(argv[2]);
    philo->time_to_eat = ft_atoi(argv[3]);
    philo->time_to_sleep = ft_atoi(argv[4]);
    philo->id_philo = malloc(sizeof(t_philo) * philo->number_of_philosophers);
    if (argc == 6)
        philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    else
        philo->number_of_times_each_philosopher_must_eat = 0; //potentielemente inutile j'ai fais un memset
}

//initialiser la vie de chaque philo avec une boucle qui donne temps + temps de mort et a chaque fois qu'il mange remettre + temps de mort a life 
void    init_philo(data_t *philo)
{
    int i;
    timeval_t time;

    i = 0;
    gettimeofday(&time, NULL);
    while (i < philo->number_of_philosophers)
    {
        philo->id_philo[i] = malloc(sizeof(t_philo));
        i++;
    }
    i = 0;
    while (i <= philo->number_of_philosophers)
    {
        philo->id_philo[i]->life = time;
        philo->id_philo[i]->life.tv_usec += 800 * 1000;
        philo->id_philo[i]->fork_left = 0;
        philo->id_philo[i]->fork_right = 1;
        philo->id_philo[i]->number = i;
        i++;
    } // apres pour les faire mourir regarder si leurs temps est plus petit ou egal au temps actuel. il doit toujours etre plus grand.
    philo->info = philo;
    return ;
    
}

void    *my_thread_to_sleep(philo_t *philo)
{
   (data_t *) philo;
    printf("Philosopher %d is sleeping\n", philo->number);
    philo->sleep = 1;
    usleep(philo->info->time_to_sleep);
    philo->sleep = 0;
    return (NULL);
}

void    *my_thread_to_eat(philo_t *philo)
{
    pthread_mutex_lock(philo->fork_left);
    printf("le philosopher %d taken a fork left", philo->number);
    pthread_mutex_lock(philo->fork_right);
    printf("le philosopher %d taken a fork right", philo->number);


    return ;
}

void    *my_thread_to_think(philo_t *philo)
{
    usleep(50);
    printf("Philosopher %d is thinking\n", philo->number);
    return (NULL);
}

//idee faire une fonction qui regarde le temps de chaque philo et quand il mange remet a 0 mais par contre si il depasse alors dit qu'il est mort 

void    *my_thread_to_die(philo_t *philo)
{
    int i;
    int	y;
	timeval_t new_time;
	
    (data_t *) philo;
    i = 0;
	y = 0;
    while (y != philo->info->number_of_philosophers)
	{
    	while (i < philo->info->number_of_philosophers)
    	{
			if (philo->info->id_philo[i]->life !=  gettimeofday(&new_time, NULL)) // trouver le moyen de mettre l'heure actuel et de refresh pour savoir quand un philo est mort
            {
				printf("Philosopher %d is dead", philo->info->id_philo[i]);
                philo->dead = 1;
			}
			i++;
    	}
		i = 0;
        y++;
	}
    return (NULL);
}
//
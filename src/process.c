/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:39:34 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/26 15:53:07 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int process_diner(data_t *philo)
{
   int i;
    int y;
    pthread_t thread_ids[philo->number_of_philosophers];
    
    i = 0;
    y = 1;
    if ((philo->number_of_philosophers % 2) == 0)
    {
        while (i < philo->number_of_philosophers)
        {
            pthread_create(&thread_ids[i], NULL, ft_routine, (void *)&philo->id_philo[i]);
            i++;
        }
    }
    i = 0;
    y = 1;
     while (i < philo->number_of_philosophers)
     {
        pthread_join(thread_ids[i], NULL);
        i++;
     }
	 return (0);
	
}


void    *ft_routine(void *args)
{
    philo_t *philo;

    philo = (philo_t *)args;
	if (args == NULL) {
        fprintf(stderr, "Erreur : argument NULL dans ft_routine\n");
        return (NULL);
    }
    if (philo->number & 1)
        usleep(50);
    while (philo->info->dead != 1)
    {
        my_thread_to_take_forks(philo);
        my_thread_to_sleep(philo); // faire sauter dormir si il n'ont pas manger 
        my_thread_to_think(philo);
    }
	return (NULL);
}

//  cre

//faire le plan suivant le nombre de philo


// 0 1 2 3 4 5 6 

// 0 mange  dors
// 1 pense  mange
// 2 mange dors 
// 3 pense  mange
// 4 mange  dors
// 5 pense  dors  mange
// 6 pense  mange  

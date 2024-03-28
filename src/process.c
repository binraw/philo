/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:39:34 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/28 15:46:57 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int process_diner(data_t *data)
{
   int i;
    int y;
    pthread_t thread_ids[data->number_of_philosophers];
    
    i = 0;
    y = 1;
    // if ((philo->number_of_philosophers % 2) == 0)
    //     usleep(1);
    
    while (i < data->number_of_philosophers)
    {
        pthread_create(&thread_ids[i], NULL, &ft_routine, (void *)data->id_philo[i]);
          
         i++;
    }
        data->all_ready = true;
  stop_routine(data, thread_ids);
    // i = 0;
    // y = 1;
    //  while (i < data->number_of_philosophers)
    //  {
    //     pthread_join(thread_ids[i], NULL);
    //     i++;
    //  }
    //  free_destroy(data);
	 return (0);
	
}

void    stop_routine(data_t *data,  pthread_t *thread_ids)
{
    int i;

    i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_join(thread_ids[i], NULL);
        i++;
    }
    free_destroy(data);
}


void    *ft_routine(void *args)
{
    philo_t *philo;

    if (args == NULL) {
        fprintf(stderr, "Erreur : argument NULL dans ft_routine\n");
        return NULL;
    }

    philo = (philo_t *)args;
        while (!(*(philo->all_ready)))
            ;

    if (philo->number & 1)
        usleep(50);
    while (philo->info->dead != 1)
    {
        my_thread_to_take_forks(philo);
        if (my_thread_to_die(philo) == -1)
            return (NULL);
        my_thread_to_think(philo);
       if (my_thread_to_die(philo) == -1)
            return (NULL);  //regler le probleme de quand ils meurs stopper la section
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

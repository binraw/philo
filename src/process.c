/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:39:34 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/20 14:10:36 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int process_diner(data_t *philo)
{
    size_t i;
    size_t y;
    
    i = 0;
    y = 1;
    if ((philo->number_of_philosophers % 2) == 0)
    {
        pthread_create(&thread1, NULL, my_thread_to_think, philo->id_philo[philo->number_of_philosophers]);
        while (i < philo->number_of_philosophers)
        {
            pthread_create(&thread2, NULL, my_thread_to_eat, philo->id_philo[i]);
            pthread_create(&thread3, NULL, my_thread_to_think, philo->id_philo[y]);
            i += 2;
            y += 2;
        } // savoir si il faut attendre la fin des threads pour envoyer les prochains
    }
    pthread_create(&thread1, NULL, my_thread_to_die, vars);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
}

//faire le plan suivant le nombre de philo


// 0 1 2 3 4 5 6 

// 0 mange  dors
// 1 pense  mange
// 2 mange dors 
// 3 pense  mange
// 4 mange  dors
// 5 pense  dors  mange
// 6 pense  mange  

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:39:34 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/21 15:39:03 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int process_diner(data_t *philo)
{
    size_t i;
    size_t y;
    pthread_t thread_ids[philo->number_of_philosophers];
    
    i = 0;
    y = 1;
    if ((philo->number_of_philosophers % 2) == 0)
    {
        while (i < philo->number_of_philosophers)
        {
            pthread_create(&thread_ids[i], NULL, "mettre ici la routine", philo->id_philo[i]);
            i++;
        } // savoir si il faut attendre la fin des threads pour envoyer les prochains
    }
    // pthread_create(&thread1, NULL, my_thread_to_die, vars);
    i = 0;
    y = 1;
     while (i < philo->number_of_philosophers)
     {
        pthread_join(thread_ids[i], NULL);
        i++;
     }
	
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

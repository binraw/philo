/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:49:20 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/19 14:07:54 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include "../lib/libft/libft.h"
# include <pthread.h>

struct data_s
{
    philo_t		**id_philo;
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;

}   data_t;

struct philo
{
    int 			number;
    int             fork_left;
    int             fork_right;
    int             hunger;
    timeval_t       life;
    int             sleep;

} philo_t;


struct timeval {
    time_t      tv_sec;     // Nombre de secondes
    suseconds_t tv_usec;    // Nombre de microsecondes
} timeval_t;


void    init_values(data_t *philo, char **argv);
void    init_philo(data_t *philo);
void    *my_thread_to_sleep(void *philo);
void    *my_thread_to_eat(void *philo);
void    *my_thread_to_think(void *philo);
void    *my_thread_to_die(void *philo);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:49:20 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/28 15:34:51 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct philo_s philo_t;

typedef struct data_s
{
  	philo_t		**id_philo;
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    int             last;
    int dead;
    pthread_mutex_t *forks;
    bool all_ready;

}   data_t;

typedef struct philo_s
{
   data_t           *info;
    int 			number;
    pthread_mutex_t            *fork_left;
    pthread_mutex_t           *fork_right;
    int             hunger;
   	int life;
    int             sleep;
    bool *all_ready;

    pthread_t thread_id;

}   philo_t;


// typedef struct timeval {
//     time_t      tv_sec;     // Nombre de secondes
//     suseconds_t tv_usec;    // Nombre de microsecondes
// } timeval_t;


void    init_values(data_t *philo, char **argv, int argc);
void    init_philo(data_t *data);
void    *my_thread_to_sleep(philo_t *philo);
void    *my_thread_to_take_forks(philo_t *philo);
void    *my_thread_to_think(philo_t *philo);
int   my_thread_to_die(philo_t *philo);
int	ft_atoi(char *str);
void    *ft_routine(void *args);
void	philo_eating(philo_t *philo);
int process_diner(data_t *philo);
int get_current_milliseconds(void);
void	free_destroy(data_t *data);
void    stop_routine(data_t *data,  pthread_t *thread_ids);
#endif
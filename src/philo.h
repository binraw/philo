#ifndef PHILO_H
# define PHILO_H


# include "../lib/libft/libft.h"

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
void    init_philo(data_t *philo, timeval_t time);
void    *my_thread_to_sleep(data_t *philo, void *args);
void    *my_thread_to_eat(data_t *philo, void *args);
void    *my_thread_to_think(data_t *philo, void *args);
void    *my_thread_to_die(data_t *philo, void *args);

#endif
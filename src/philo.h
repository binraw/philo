#ifndef PHILO_H
# define PHILO_H


# include "../lib/libft/libft.h"

struct data_s
{
    philo_t		*id_philo;
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
    int             life;
    int             sleep;

} philo_t;


void    init_values(data_t *philo, char **argv);

#endif
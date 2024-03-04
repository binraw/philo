#ifndef PHILO_H
# define PHILO_H


# include "../lib/libft/libft.h"

struct data_s
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;

}   data_t;



#endif
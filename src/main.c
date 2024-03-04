#include "philo.h"

int  main(int argc, char **argv)
{

}

void    init_values(data_t *philo, char **argv)
{
    philo->number_of_philosophers =  ft_atoi(argv[1]);
    philo->time_to_die = ft_atoi(argv[2]);
    philo->time_to_eat = ft_atoi(argv[3]);
    philo->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    else
        philo->number_of_times_each_philosopher_must_eat = 0;
}
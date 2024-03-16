#include "philo.h"

int  main(int argc, char **argv)
{
    data_t **vars;

    init_values(vars, argv);
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


void    *my_thread_to_sleep(data_t *philo, void *args)
{
    usleep(philo->time_to_sleep); // mettre une valeur
    printf("Philosopher %d is sleeping\n", (int) args ); // mettre la position du philo
    return (NULL);
}

void    *my_thread_to_eat(data_t *philo, void *args)
{
    usleep(philo->time_to_eat);
    printf("Philosopher %d is eating\n", (int) args );
    return (NULL);
}

void    *my_thread_to_think(data_t *philo, void *args)
{
    usleep(50);
    printf("Philosopher %d is thinking\n", (int) args);
    return (NULL);
}
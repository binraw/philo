#include "philo.h"

int  main(int argc, char **argv)
{
    data_t **vars;
    timeval_t time;
    gettimeofday(&time, NULL);

    memset(&vars, 0, sizeof(vars));
    init_values(vars, argv);
}

void    init_values(data_t *philo, char **argv)
{
    philo->number_of_philosophers =  ft_atoi(argv[1]);
    philo->time_to_die = ft_atoi(argv[2]);
    philo->time_to_eat = ft_atoi(argv[3]);
    philo->time_to_sleep = ft_atoi(argv[4]);
    philo->id_philo = malloc(sizeof(t_philo) * philo->number_of_philosophers);
    if (argc == 6)
        philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    else
        philo->number_of_times_each_philosopher_must_eat = 0; //potentielemente inutile j'ai fais un memset
}

//initialiser la vie de chaque philo avec une boucle qui donne temps + temps de mort et a chaque fois qu'il mange remettre + temps de mort a life 
void    init_philo(data_t *philo, timeval_t time)
{
    int i;

    i = 0;
    while (i < philo->number_of_philosophers)
    {
        philo->id_philo[i] = malloc(sizeof(t_philo));
        i++;
    }
    i = 0;
    while (i < philo->number_of_philosophers)
    {
        philo->id_philo[i]->life = time;
        philo->id_philo[i]->life.tv_usec += 800 * 1000;
        philo->id_philo[i]->fork_left = 1;
        philo->id_philo[i]->fork_right = 0;
        i++;
    } // apres pour les faire mourir regarder si leurs temps est plus petit ou egal au temps actuel. il doit toujours etre plus grand.
    return ;
}

void    *my_thread_to_sleep(data_t *philo, void *args)
{
   
    printf("Philosopher %d is sleeping\n", (int) args ); // mettre la position du philo
    philo->id_philo[(int)args]->sleep = 1;
    usleep(philo->time_to_sleep); // mettre une valeur
    philo->id_philo[(int)args]->sleep = 0;
    return (NULL);
}

void    *my_thread_to_eat(data_t *philo, void *args)
{
    printf("Philosopher %d is eating\n", (int) args );
    usleep(philo->time_to_eat);
    //au dessus enlever une fork a voisin de droite puis lui redonner
    return (NULL);
}

void    *my_thread_to_think(data_t *philo, void *args)
{
    usleep(50);
    printf("Philosopher %d is thinking\n", (int) args);
    return (NULL);
}

//ideee faire une fonction qui regarde le temps de chaque philo et quand il mange remet a 0 mais par contre si il depasse alors dit qu'il est mort 

void    *my_thread_to_die(data_t *philo, void *args)
{

}
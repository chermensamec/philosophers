#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct s_philo
{
	int				index;
	int				count_eat;
	sem_t			*fork;
	long long		time_eat;
	struct s_data	*link;
}	t_philo;

typedef struct s_data
{
	int		numb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_must_eat;
	int		error;
	long long	time_start;	
	t_philo	**philosophers;
	pthread_mutex_t	*fork;
	pthread_mutex_t	log;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	count_mutex;
	pthread_mutex_t	time_mutex;
	pthread_t		*pthreads;
}		t_data;

#endif 
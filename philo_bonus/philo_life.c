#include "philo_bonus.h"

void	*philo_life(void	*param)
{
		t_philo *philo;

		philo = param;
		while (philo->link->times_must_eat)
		{
			sem_wait(philo->link->forks);
			logs("has taken a fork", philo);
			sem_wait(philo->link->forks);
			logs("has taken a fork", philo);
			logs("is eating", philo);
			philo->time_eat = current_time();
			my_sleep(philo->link->time_to_eat);
			sem_post(philo->link->forks);
			sem_post(philo->link->forks);
			logs("is sleeping", philo);
			my_sleep(philo->link->time_to_sleep);
			logs("is thinking", philo);
			if (philo->link->times_must_eat != -1)
				philo->link->times_must_eat--;
		}
	exit(0);
}

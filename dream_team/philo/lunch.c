#include "philo.h"

void	*lunch(void *param)
{
	t_philo	*philo;
	philo = (t_philo *)param;
	pthread_mutex_lock(&philo->link->time_mutex);
	philo->time_eat = current_time();
	pthread_mutex_unlock(&philo->link->time_mutex);
	if (philo->index % 2)
		my_sleep(1);
	while (1)
	{
		if (philo->count_eat == philo->link->times_must_eat)
		{
			return (NULL);
		}
		pthread_mutex_lock(philo->left);
		logs("has taken a fork", philo);
		if (philo->link->numb_philo == 1)
		{
			pthread_mutex_unlock(philo->left);
			philo->alive = 0;
			return (NULL);
		}
		pthread_mutex_lock(philo->right);
		logs("has taken a fork", philo);
		logs("is eating", philo);
		pthread_mutex_lock(&philo->link->time_mutex);
		philo->time_eat = current_time();
		pthread_mutex_unlock(&philo->link->time_mutex);
		pthread_mutex_lock(&philo->link->count_mutex);
		philo->count_eat++;
		pthread_mutex_unlock(&philo->link->count_mutex);
		my_sleep(philo->link->time_to_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		logs("is thinking", philo);
		logs("is sleeping", philo);
		my_sleep(philo->link->time_to_sleep);
	}
	return (NULL);
}

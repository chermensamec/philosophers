#include "philo.h"

int	is_alive(t_philo *philo)
{
	if (current_time() - philo->time_eat >= philo->link->time_to_die)
	{
		printf("num %d count %d\n", philo->index, philo->count_eat);
			return (0);
	}	
	return (1);
}

void	logs(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->link->log);
	printf("%lld %d %s\n", current_time() - philo->link->time_start, philo->index,  str);
	pthread_mutex_unlock(&philo->link->log);
}

void	*lunch(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	// philo->time_eat = current_time();
	if (philo->index % 2)
		usleep(1000000);
	while (is_alive(param))
	{
		pthread_mutex_lock(philo->left);
		logs("has taken a left fork", philo);
		pthread_mutex_lock(philo->right);
		logs("has taken a right fork", philo);
		philo->time_eat = current_time();
		logs("is eating", philo);
		philo->count_eat++;
		usleep(philo->link->time_to_eat * 1000);
		pthread_mutex_unlock(philo->left);
		logs("has return a fork", philo);
		pthread_mutex_unlock(philo->right);
		logs("has return a fork", philo);
		logs("is sleeping", philo);
		usleep(philo->link->time_to_sleep * 1000);
		logs("is thinking", philo);
		printf("%d eating %d\n", philo->index, philo->count_eat);
	}
	return (NULL);
}

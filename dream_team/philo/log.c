#include "philo.h"

void	logs(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->link->log);
	printf("%lld %d %s\n", current_time() - philo->link->time_start, philo->index + 1,  str);
	pthread_mutex_unlock(&philo->link->log);
}
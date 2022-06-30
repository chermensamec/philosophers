#include "philo.h"

long long current_time()
{
	struct timeval	now; 
	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}
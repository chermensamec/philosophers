#include "philo.h"

void	my_sleep(int time)
{
	struct timeval	now; 
	struct timeval	begin;

	gettimeofday(&now, NULL);
	gettimeofday(&begin, NULL);
	while ((now.tv_sec - begin.tv_sec) * 1000 + (now.tv_usec - begin.tv_usec) / 1000 < time)
	{
		usleep(210);
		gettimeofday(&now, NULL);
	}
}

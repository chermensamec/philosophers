#include "philo_bonus.h"

int	check_philo_healf(t_philo *philo)
{
	while (1)
	{
		if (current_time() - philo->time_eat \
				> philo->link->time_to_die)
		{
			logs("died", philo);
			exit (1);
		}
		if (philo->link->times_must_eat != -1 && philo->link->times_must_eat \
			<= philo->count_eat)
		{
			exit (1);
		}
	}
}

void	init_proc(t_data *data)
{
	int i;
	
	i = 0;
	data->time_start = current_time();
	while (i != data->numb_philo)
	{
		data->p_id[i] = fork();
		if(data->p_id[i] == -1)
			exit(1);
		if (data->p_id[i] == 0)
		{
			pthread_create(&data->philosophers[i]->philo_pthread, NULL, \
					philo_life, data->philosophers[i]);
			pthread_detach(data->philosophers[i]->philo_pthread);
			check_philo_healf(data->philosophers[i]);
		}
		i++;
	}
}

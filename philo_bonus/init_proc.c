#include "philo_bonus.h"

void	init_proc(t_data *data)
{
	int i;
	
	i = 0;
	while (i != data->numb_philo)
	{
		data->p_id[i] = fork();
		if(data->p_id[i] == -1)
			exit(1);
		if (data->p_id[i] == 0)
		{
			pthread_create(&data->philo_pthread, NULL, \
					philo_life, data->philosophers[i]);
			pthread_detach(data->philo_pthread);
			check_philo_healf(data);
		}
	}
}

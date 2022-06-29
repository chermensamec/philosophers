#include "philo.h"

void	set_param(t_data *data, int argc, char **argv)
{
	data->numb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);	
	if (data->numb_philo < 2 || data->time_to_die < 1\
			|| data->time_to_eat < 1 || data->time_to_sleep < 1\
			|| (argc == 6 && data->times_must_eat < 1))
		data->error = 1;
}

void	create_pthreads(t_data *data)
{
	int	i;
	i = 0;
	data->pthread = malloc(sizeof(pthread_t) * data->numb_philo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->numb_philoi);
	while (i < data->numb_philo)
	{
		pthread_create(data->pthread + i, NULL, lunch, data->philosophers[i]);
		mutex_create(data->fork + i);
	}
}

t_data	*init(int argc, char **argv)
{
	t_data	*data;

   	data = (t_data *)malloc(sizeof(t_data));	
	data->error = 0;	
	if (argc != 5 && argc != 6)
		data->error = 1;	
	set_param(data, argc, argv);
	if (argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
	else 
		data->times_must_eat = -1;
	create_threads(data);
	return (data);
}

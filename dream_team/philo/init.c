#include "philo.h"

void	set_param(t_data *data, int argc, char **argv)
{
	data->numb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);	
	if (data->numb_philo < 1 || data->time_to_die < 1\
			|| data->time_to_eat < 1 || data->time_to_sleep < 1\
			|| (argc == 6 && data->times_must_eat < 1))
		data->error = 1;
}

void	create_philosophers(t_data *data)
{
	int	i;
	
	i = 0;
	data->philosophers = malloc(sizeof(t_philo *) * data->numb_philo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->numb_philo);
	while (i < data->numb_philo)
		pthread_mutex_init(data->fork + i++, NULL);
	i = 0;
	while(i < data->numb_philo)
	{
		data->philosophers[i] = malloc(sizeof(t_philo));
		data->philosophers[i]->left = data->fork + i;	
		data->philosophers[i]->right = data->fork +((i + 1) % (data->numb_philo));
		data->philosophers[i]->index = i;
		data->philosophers[i]->count_eat = 0;
		data->philosophers[i]->time_eat = 0;
		data->philosophers[i]->link = data;
		data->philosophers[i]->alive = 1;
		data->philosophers[i]->time_eat = current_time();
		i++;
	}
}

void	create_pthreads(t_data *data)
{
	int i;

	i = 0;
	data->pthreads = malloc(sizeof(pthread_t) * data->numb_philo);
	data->time_start = current_time();
	while (i < data->numb_philo)
	{
		pthread_create(data->pthreads + i, NULL, lunch, data->philosophers[i]);
		i++;
	}
}

t_data	*init(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));	
	data->error = 1;
	if (argc != 5 && argc != 6)
   		return (data);
	data->error = 0;
	if (argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
	else 
		data->times_must_eat = -1;
	set_param(data, argc, argv);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->count_mutex, NULL);
	pthread_mutex_init(&data->time_mutex, NULL);
	create_philosophers(data);
	return (data);
}

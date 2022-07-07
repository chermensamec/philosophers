/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:37:05 by onelda            #+#    #+#             */
/*   Updated: 2022/07/07 19:26:53 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_param(t_data *data, char **argv)
{
	data->numb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
}

int	set_philosophers_param(t_data *data, int i)
{
	data->philosophers[i] = malloc(sizeof(t_philo));
	if (!data->philosophers[i])
		return (1);
	data->philosophers[i]->index = i;
	data->philosophers[i]->link = data;
	data->philosophers[i]->time_eat = current_time();
	return (0);
}

int	create_philosophers(t_data *data)
{
	int	i;

	i = 0;
	data->p_id = malloc(sizeof(pid_t) * data->numb_philo);
	data->philosophers = malloc(sizeof(t_philo *) * data->numb_philo);
	if (!data->philosophers)
		return (free_error(1, data, 0));
	i = 0;
	while (i < data->numb_philo)
	{
		if (set_philosophers_param(data, i))
			return (free_error(2, data, 1));
		i++;
	}
	return (0);
}

void	create_semathors(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("log");
	sem_unlink("time");	
	sem_unlink("must_eat");
	data->forks = sem_open("forks", O_CREAT | O_EXCL, 0777, data->numb_philo);
	data->time = sem_open("time", O_CREAT | O_EXCL, 0777, 1);
	data->log = sem_open("log", O_CREAT | O_EXCL, 0777, 1);	
	data->must_eat = sem_open("must_eat", O_CREAT | O_EXCL, 0777, 1);
}

t_data	*init(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->error = 1;
	if ((argc != 5 && argc != 6) || !data)
		return (data);
	data->error = 0;
	if (argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
	else
		data->times_must_eat = -1;
	set_param(data, argv);
	if (data->error)
	{
		printf("error");
		free(data);
		exit(1);
	}
	data->error = create_philosophers(data);
	create_semathors(data);
	return (data);
}

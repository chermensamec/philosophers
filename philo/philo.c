/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:07:05 by sbart             #+#    #+#             */
/*   Updated: 2022/07/08 16:37:12 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	detach_pthread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numb_philo)
		pthread_detach(data->pthreads[i++]);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		free(data->philosophers[i++]);
	}
	pthread_mutex_destroy(&data->log);
	pthread_mutex_destroy(&data->eat_mutex);
	pthread_mutex_destroy(&data->count_mutex);
	pthread_mutex_destroy(&data->time_mutex);
	free(data->philosophers);
	free(data->fork);
	free(data->pthreads);
	free(data);
}

int	check_param(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc != 5 && argc != 6)
		return (1);
	while (i < argc)
	{	
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_param(argc, argv))
	{
		printf("error\n");
		return (0);
	}
	data = init(argc, argv);
	if (!data || data->error)
	{
		free(data);
		printf("error\n");
		return (0);
	}
	if (create_pthreads(data))
		free_error(3, data, data->numb_philo);
	else
	{
		check_dead(data);
		detach_pthread(data);
		free_data(data);
	}
}

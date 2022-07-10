/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_done.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:24:49 by onelda            #+#    #+#             */
/*   Updated: 2022/07/08 18:39:03 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_eat(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numb_philo)
	{
		pthread_mutex_lock(&data->eat_mutex);
		if (data->philosophers[i]->count_eat < data->times_must_eat)
		{
			pthread_mutex_unlock(&data->eat_mutex);
			return (0);
		}
		pthread_mutex_unlock(&data->eat_mutex);
		i++;
	}
	return (1);
}

int	loop_dead(t_data *data, int i)
{
	while (i != data->numb_philo)
	{
		pthread_mutex_lock(&data->time_mutex);
		if (current_time() - data->philosophers[i]->time_eat \
				> data->time_to_die)
		{
			logs("died", data->philosophers[i]);
			pthread_mutex_unlock(&data->time_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->time_mutex);
		pthread_mutex_lock(&data->count_mutex);
		if (data->times_must_eat != -1 && data->times_must_eat \
			<= data->philosophers[i]->count_eat)
		{
			if (check_all_eat(data))
			{
				pthread_mutex_unlock(&data->count_mutex);
				return (1);
			}
		}
		pthread_mutex_unlock(&data->count_mutex);
		i++;
	}
	return (0);
}

void	check_dead(t_data *data)
{
	while (1)
	{
		if (loop_dead(data, 0))
			return ;
		usleep(1000);
	}
}

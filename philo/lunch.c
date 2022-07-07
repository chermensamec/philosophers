/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:33:40 by onelda            #+#    #+#             */
/*   Updated: 2022/07/06 14:36:23 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	life_phil(t_philo	*philo)
{
	if (philo->count_eat == philo->link->times_must_eat)
		return (1);
	pthread_mutex_lock(philo->left);
	logs("has taken a fork", philo);
	pthread_mutex_lock(philo->right);
	logs("has taken a fork", philo);
	logs("is eating", philo);
	pthread_mutex_lock(&philo->link->time_mutex);
	philo->time_eat = current_time();
	pthread_mutex_unlock(&philo->link->time_mutex);
	pthread_mutex_lock(&philo->link->count_mutex);
	philo->count_eat++;
	pthread_mutex_unlock(&philo->link->count_mutex);
	my_sleep(philo->link->time_to_eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	logs("is thinking", philo);
	logs("is sleeping", philo);
	my_sleep(philo->link->time_to_sleep);
	return (0);
}

void	*lunch(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(&philo->link->time_mutex);
	philo->time_eat = current_time();
	pthread_mutex_unlock(&philo->link->time_mutex);
	if (philo->index % 2)
		my_sleep(1);
	while (1)
	{
		if (life_phil(philo))
			return (NULL);
	}
	return (NULL);
}

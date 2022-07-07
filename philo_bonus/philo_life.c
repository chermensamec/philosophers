/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:55 by onelda            #+#    #+#             */
/*   Updated: 2022/07/07 17:30:05 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*philo_life(void	*param)
{
	t_philo	*philo;

	philo = param;
	while (philo->link->times_must_eat)
	{
		sem_wait(philo->link->forks);
		logs("has taken a fork", philo);
		sem_wait(philo->link->forks);
		logs("has taken a fork", philo);
		logs("is eating", philo);
		sem_wait(philo->link->time);
		philo->time_eat = current_time();
		sem_post(philo->link->time);
		my_sleep(philo->link->time_to_eat);
		sem_post(philo->link->forks);
		sem_post(philo->link->forks);
		if (philo->link->times_must_eat != -1)
			philo->link->times_must_eat--;
		logs("is sleeping", philo);
		my_sleep(philo->link->time_to_sleep);
		logs("is thinking", philo);
	}
	exit(0);
}

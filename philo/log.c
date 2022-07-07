/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:35:30 by onelda            #+#    #+#             */
/*   Updated: 2022/07/07 16:45:47 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	logs(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->link->count_mutex);
	if (philo->count_eat < philo->link->times_must_eat || \
	philo->link->times_must_eat == -1)
	{
		pthread_mutex_lock(&philo->link->log);
		printf("%lld %d %s\n", current_time() \
			- philo->link->time_start, philo->index + 1, str);
		pthread_mutex_unlock(&philo->link->log);
	}
	pthread_mutex_unlock(&philo->link->count_mutex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:35:30 by onelda            #+#    #+#             */
/*   Updated: 2022/07/07 16:43:11 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	logs(char *str, t_philo *philo)
{
	
	if (philo->count_eat < philo->link->times_must_eat || philo->link->times_must_eat == -1)
	{
		sem_wait(philo->link->log);
		printf("%lld %d %s\n", current_time() \
			- philo->link->time_start, philo->index + 1, str);
		if (str[0] != 'd')
			sem_post(philo->link->log);
	}
}

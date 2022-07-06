/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:30:38 by onelda            #+#    #+#             */
/*   Updated: 2022/07/06 14:46:47 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	my_sleep(int time)
{
	long long	end;

	end = current_time() + time;
	while (current_time() < end)
		usleep(time);
}

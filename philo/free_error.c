/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:10:58 by onelda            #+#    #+#             */
/*   Updated: 2022/07/08 15:28:54 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_error(int error, t_data *data, int n)
{
	int	i;

	if (error >= 3)
		free(data->pthreads);
	if (error >= 2)
	{
		i = 0;
		while (i < n)
			free(data->philosophers[i++]);
		free(data->philosophers);
	}
	if (error >= 1)
		free(data->fork);
	return (1);
}

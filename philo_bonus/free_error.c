/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:24:57 by onelda            #+#    #+#             */
/*   Updated: 2022/07/07 15:47:29 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	free_error(int error, t_data *data, int n)
{
	int	i;

	if (error >= 2)
	{
		i = 0;
		while (i < n)
			free(data->philosophers[i++]);
		free(data->philosophers);
	}
	free(data->p_id);
	return (1);
}

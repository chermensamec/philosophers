/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:07:05 by sbart             #+#    #+#             */
/*   Updated: 2022/07/06 13:11:11 by onelda           ###   ########.fr       */
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
		free(data->philosophers[i++]);
	free(data->philosophers);
	free(data->fork);
	free(data->pthreads);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init(argc, argv);
	if (data->error)
	{
		printf("error");
		return (0);
	}
	create_pthreads(data);
	check_dead(data);
	detach_pthread(data);
	free_data(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:07:05 by sbart             #+#    #+#             */
/*   Updated: 2022/06/30 21:50:44 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_pthread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numb_philo)
	{
		pthread_join(data->pthreads[i++], NULL);
	}
}

int	main(int argc, char **argv)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	data = init(argc, argv);
	if (data->error == 1)
	{
		printf("error");
		return (0);
	}
	create_pthreads(data);
	join_pthread(data);
	printf("%d\n", data->numb_philo);
	printf("%d\n", data->time_to_die);
	printf("%d\n", data->time_to_eat);
	printf("%d\n", data->time_to_sleep);
	printf("%d\n", data->times_must_eat);
}

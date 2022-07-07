/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:07:05 by sbart             #+#    #+#             */
/*   Updated: 2022/07/07 21:09:57 by onelda           ###   ########.fr       */
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

void	check_param(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i != argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				printf("error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	check_param(argc, argv);
	data = init(argc, argv);
	if (data->error)
	{
		free(data);
		printf("error\n");
		return (0);
	}
	create_pthreads(data);
	check_dead(data);
	detach_pthread(data);
	free_data(data);
}

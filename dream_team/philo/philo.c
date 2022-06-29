/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:07:05 by sbart             #+#    #+#             */
/*   Updated: 2022/06/29 22:19:02 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	printf("%d\n", data->numb_philo);
	printf("%d\n", data->time_to_die);
	printf("%d\n", data->time_to_eat);
	printf("%d\n", data->time_to_sleep);
	printf("%d\n", data->times_must_eat);
}

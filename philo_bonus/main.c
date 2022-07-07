/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:33 by onelda            #+#    #+#             */
/*   Updated: 2022/07/07 21:11:27 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*void	free_sem(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->log);
	sem_close(data->time);
	sem_unlink("fork");
	sem_unlink("log");
	sem_unlink("time");
}*/

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numb_philo)
		free(data->philosophers[i++]);
	free(data->philosophers);
	free(data->p_id);
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

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		i;

	check_param(argc, argv);
	i = 0;
	data = init(argc, argv);
	if (data->error)
	{
		free(data);
		printf("error");
		return (0);
	}
	init_proc(data);
	waitpid(-1, NULL, 0);
	while (i < data->numb_philo)
	{
		kill(data->p_id[i++], 9);
	}
	i = 0;
	while (i++ < data->numb_philo)
		waitpid(data->p_id[i], NULL, 0);
	//free_sem(data);
	free_data(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:33 by onelda            #+#    #+#             */
/*   Updated: 2022/07/08 16:41:20 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_sem(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->log);
	sem_close(data->time);
	sem_unlink("fork");
	sem_unlink("log");
	sem_unlink("time");
}

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

	i = 0;
	if (argc != 5 && argc != 6)
		exit(write(1, "error\n", 6));
	while (++i != argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				exit(write(1, "error\n", 6));
		}
		if (ft_atoi(argv[i]) > 2147483647)
			exit(write(1, "error\n", 6));
	}
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		i;

	check_param(argc, argv);
	i = 0;
	data = init(argc, argv);
	if (!data || data->error)
	{
		if (data)
			free(data);
		printf("error1\n");
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
	free_sem(data);
	free_data(data);
}

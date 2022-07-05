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
	//if (error >= 1)
		//free(data->fork);
	return (1);
}

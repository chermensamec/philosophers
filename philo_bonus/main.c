#include "philo_bonus.h"

int main(int argc, char *argv[])
{
	t_data *data;
	int	i;

	i = 0;
	data = init(argc, argv);
	while (i != data->numb_philo)
	{
		data->p_id[i] = fork();
		if (data->p_id[i] == 0)
			philo_life(data, i);
		i++;
	}
	i = 0;
	waitpid(-1, NULL, 0);
	i = 0;
	while(i < data->numb_philo)
	{
		kill(data->p_id[i], 9);
		i++;
	}
	printf("index main%d\n", data->numb_philo);
}

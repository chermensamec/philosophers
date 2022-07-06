#include "philo_bonus.h"

void	free_sem(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->log);
	sem_unlink("fork");
	sem_unlink("log");	
}

int main(int argc, char *argv[])
{
	t_data *data;
	int	i;

	i = 0;
	data = init(argc, argv);
	init_proc(data);
	my_sleep(1000);

	waitpid(-1, NULL, 0);
	while (i < data->numb_philo)
	{
		kill(data->p_id[i++], 9);
	}
	i = 0;
	while (i++ < data->numb_philo)
		waitpid(data->p_id[i], NULL, 0);
	printf("index main %d\n", data->numb_philo);
	free_sem(data);
}

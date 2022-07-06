#include "philo_bonus.h"

int main(int argc, char *argv[])
{
	t_data *data;
	int	i;

	i = 0;
	data = init(argc, argv);
	
	printf("index main%d\n", data->numb_philo);
}

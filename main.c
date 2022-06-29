#include "philosophers.h"

void	*routine(void	*data)
{
	routine_val	*k;

	k = data;
	for (int i = 0; i < 30000000; i++)
	{
		pthread_mutex_lock(&k->lock_increment);
		(((routine_val *)data)->i)++;
		pthread_mutex_unlock(&k->lock_increment);
	}	
	return (NULL);
}

int main()
{
	routine_val *data;
	clock_t	begin;
	data = init_routine_val(3);
	//begin = te
	pthread_create(data->p, NULL, routine, data);
	pthread_create(data->p + 1, NULL, routine, data);
	pthread_create(data->p + 2, NULL, routine, data);
	pthread_join(*data->p, NULL);
	pthread_join(*(data->p + 1), NULL);	
	pthread_join(*(data->p + 2), NULL);
	printf("%d\n", data->i);
	return (0);
}

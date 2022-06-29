#include "philosophers.h"

routine_val	*init_routine_val(int n)
{
	routine_val	*val;

	val = malloc(sizeof(routine_val));
	val->i = 0;
	pthread_mutex_init(&val->lock_increment, NULL);
	val->p = malloc(sizeof(pthread_t) * n);
	return (val);
}

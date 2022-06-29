#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct 
{
	pthread_t		*p;
	pthread_mutex_t	lock_increment;
	int				i;
} routine_val;

routine_val	*init_routine_val(int n);

#endif

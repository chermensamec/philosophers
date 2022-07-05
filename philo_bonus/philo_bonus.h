#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct s_philo
{
	int		index;
	int		count_eat;
	long long	time_eat;
	struct s_data	*link;	
	pid_t		p_id;
}	t_philo;

typedef struct s_data
{
	int		numb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_must_eat;
	int		error;
	long long	time_start;	
	t_philo		**philosophers;
}		t_data;

int	ft_atoi(const char *string);
int	free_error(int error, t_data *data, int n);
long long	current_time(void);

#endif 

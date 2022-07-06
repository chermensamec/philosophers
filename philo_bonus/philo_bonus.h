#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
typedef struct s_philo
{
	int		index;
	int		count_eat;
	long long	time_eat;
	pthread_t	philo_pthread;
	struct s_data	*link;	
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
	pid_t		*p_id;
	sem_t		forks;
	t_philo		**philosophers;
}		t_data;

t_data	*init(int argc, char **argv);
int	ft_atoi(const char *string);
int	free_error(int error, t_data *data, int n);
long long	current_time(void);
void philo_life(t_data *data, int i);
#endif 

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:28:32 by onelda            #+#    #+#             */
/*   Updated: 2022/07/07 17:31:46 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <fcntl.h>
typedef struct s_philo
{
	int				index;
	long long		time_eat;
	pthread_t		philo_pthread;
	struct s_data	*link;	
}	t_philo;

typedef struct s_data
{
	int			numb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_must_eat;
	int			error;
	long long	time_start;		
	pid_t		*p_id;
	sem_t		*forks;
	sem_t		*log;
	sem_t		*time;
	sem_t		*must_eat;
	t_philo		**philosophers;
}		t_data;

t_data		*init(int argc, char **argv);
int			ft_atoi(const char *string);
int			free_error(int error, t_data *data, int n);
long long	current_time(void);
void		*philo_life(void	*param);
void		logs(char *str, t_philo *philo);
void		my_sleep(int time);
void		init_proc(t_data *data);
#endif 

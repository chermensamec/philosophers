/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:06:57 by sbart             #+#    #+#             */
/*   Updated: 2022/07/04 18:28:21 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h> 
# include <unistd.h>

typedef struct s_philo
{
	int				index;
	int				count_eat;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	long long		time_eat;
	struct s_data	*link;
}	t_philo;

typedef struct s_data
{
	int				numb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				error;
	long long		time_start;	
	t_philo			**philosophers;
	pthread_mutex_t	*fork;
	pthread_mutex_t	log;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	count_mutex;
	pthread_mutex_t	time_mutex;
	pthread_t		*pthreads;
}		t_data;

void		my_sleep(int time);
int			ft_atoi(const char *string);
t_data		*init(int argc, char **argv);
void		*lunch(void *param);
long long	current_time(void);
void		create_pthreads(t_data *data);
void		logs(char *str, t_philo *philo);
void		check_dead(t_data *data);

#endif

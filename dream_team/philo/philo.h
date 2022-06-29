/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:06:57 by sbart             #+#    #+#             */
/*   Updated: 2022/06/29 22:18:56 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h> 

typedef struct s_philo
{
	int				index;
	int				cout_eat;
	int				alive;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	long long		time_eat;
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
	t_philo	*philosophers;
	pthread_mutex_t	*fork;
	pthread_mutex_t	log;
	pthread_t		*pthreads;

}		t_data;


int		ft_atoi(const char *string);
t_data	*init(int argc, char **argv);
#endif

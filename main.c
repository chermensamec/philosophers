#include <stdio.h>
#include <pthread.h>

void	*routine(void	*j)
{
	int	*k;

	k = j;
	for (int i = 0; i < 200000; i++)
		(*k)++;
	return (NULL);
}

int main()
{
	int			i;
	pthread_t	p[1];
	i = 0;
	pthread_create(p, NULL, routine, &i);
	//pthread_create(p + 1, NULL, routine, &i);
	//pthread_detach(*p);
	pthread_join(*(p), NULL);
	printf("%d\n", i);
	return (0);
}

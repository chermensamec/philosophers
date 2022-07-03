#include "philo.h"

void    my_sleep(int time)
{
    long long   end;
    end = current_time() + time;
    while (current_time() < end)
        usleep(time);
}

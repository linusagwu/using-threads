#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * counting(void * arg)
{
    int threadid = *(int *) arg; 
    for( int i = 1; i <= 100; i++)
    {
        printf("thread %d is counting %d.\n",threadid, i);
    }
    return NULL;
}

int main()
{
    pthread_t t_id[3];
    int ids[3];
    for(int i = 1; i<=3; i++)
    {
        ids[i] =  i;
    }
    for(int i = 1 ; i<=3; i++)
    {
        pthread_create(&t_id[i], NULL, counting, (void *) & ids[i]);
        pthread_join(t_id[i], NULL);
    }
    for(int i = 1; i<3; i++)
    { 
        pthread_join(t_id[i], NULL);
    }
    return 0;
}
#include <iostream>
#include <pthread.h>
using namespace std;

#define N_PTHREADS 4
#define N_ARRAY 20

int array[N_ARRAY];

void *my_pthread_fn(void *arg)
{
    int *start = (int *)arg;

    return NULL;
}

int main()
{
    int res;
    pthread_t mythread[N_PTHREADS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    for (int i = 0; i < N_PTHREADS; i++)
    {
        res = pthread_create(&mythread[i], &attr, my_pthread_fn, (void *)(0 + ((N_ARRAY / N_PTHREADS) * i)));

        if (res != 0)
        {
            cout << "Creazione pthread " << mythread[i] << "fallita..." << endl;
            return -1;
        }
    }

    pthread_attr_destroy(&attr);

    for (int i = 0; i < N_PTHREADS; i++)
    {
        pthread_join(mythread[i], NULL);
    }

    return 0;
}
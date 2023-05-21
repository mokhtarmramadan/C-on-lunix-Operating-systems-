#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


void *thread_one(void *arg)
{
    int *p = (int *)arg;
    int * sum = malloc(sizeof(int));

    for(int i =0; i < 10; i ++)
    {
        *sum += p[i];
    }
}



int main(void)
{

    // Inatialize, create T1, T2 threads and wait for them to finish
    pthread_t T1;
    
    void *result;
    int arr[10] = {1, 2,3,4,5,6,7,8,9,10};

    pthread_create(&T1, NULL, thread_one, (void *) arr);    
    pthread_join(T1, &result);

    printf("Sum %d\n", *((char *)result));
    
}
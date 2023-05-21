#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int count = 5;

void *thread_one();
void *thread_two();

int main (void)
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_one, NULL);
    pthread_create(&t2, NULL, thread_two, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value of count is %d\n", count);
}

void *thread_one()
{
    int x;
    x = count;
    printf("Thread one read the value of count as %d\n", x);
    x ++;
    printf("Thread one updated the value of count to %d\n", x);
    sleep(1);
    count = x;
    printf("Thread one updated count to equal x = %d\n", count);
}

void *thread_two()
{
    int y;
    y = count;
    printf("Thread two read the value of count as %d\n", y);
    y --;
    printf("Thread two updated the value of count to %d\n", y);
    sleep(1);
    count = y;
    printf("Thread two updated count to equal y = %d\n", count);
}

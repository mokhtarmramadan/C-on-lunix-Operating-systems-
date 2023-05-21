#include<stdio.h>
#include<pthread.h>
#include <fcntl.h>
#include<unistd.h>

// Thread_one function to open a file called thread.txt in the create mode and give us all the access to it and then closese it
void *thread_one(void *arg)
{
    int file = open("thread.txt", O_CREAT, 0642);
    close(file);
}

// Thread_two function to open thread.txt file in readonly mode and wirte to it
void *thread_two(void *arg)
{
    int file = open("thread.txt", O_WRONLY);
    write(file, "I'm thread 2", 12);
}

int main(void)
{
    // Inatialize, create T1, T2 threads and wait for them to finish
    pthread_t T1, T2;
    pthread_create(&T1, NULL, thread_one, NULL);    
    pthread_join(T1, NULL);
    pthread_create(&T2, NULL, thread_two, NULL);
    pthread_join(T2, NULL);

}
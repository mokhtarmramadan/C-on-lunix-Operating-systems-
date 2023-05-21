// Program using fork() system call to create two childs of the same process i.e parent P having P1 as a child and P1 having P2 as a child 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 
#include<sys/types.h>

int main(void)
{
    // Inatialize the process
    pid_t P;

    // Fork the process
    P = fork();

    // Check if the process is forked
    if( P == 0)
    {
        printf("I'm the first child ID = %d \n", getpid());
        printf("My parent process ID = %d\n", getppid());
    }

    else
    {
        printf("I'm the parent of the first child ID = %d\n", P);
        printf("my ID = %d\n", getpid());
    }


    pid_t P1;

    P1 = fork();

    // Check if the second process is forked
    if( P1 == 0)
    {
        printf("I'm the second child ID = %d \n", getpid());
        printf("My parent process ID = %d\n", getppid());
    }

    else
    {
        printf("I'm the parent of the Second child ID = %d\n", P);
        printf("my ID = %d\n", getpid());
    }
    

}
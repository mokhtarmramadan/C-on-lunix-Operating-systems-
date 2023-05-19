// Program to create threads in linux. Thread prints 0-4 while the main process prints 20-24

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<wait.h>
#include<pthread.h>

// Define thread funcion takes and returns no arguments
void *fun1(void *arg)
{	
	int j;
	
	printf("Inside the tread\n");
	
	for(j = 0; j <5; j ++)
	{
		printf("%i\n", j);
		sleep(1);
		
	}
}


int main()
{	
	int i;
	// Declaration of thread T1
	pthread_t T1;
	
	// Creation of threa T1 and passing the function fun1 to it
	pthread_create(&T1, NULL, fun1, NULL);
	
	// Waiting for the thread T1 to finish excuting so we can excute the main program
	pthread_join(T1, NULL);
	
	// Excute the main program
	printf("Inside the main program\n");
	for(int i = 20; i <25; i ++)
	{
		printf("%d\n", i);
		sleep(1);
	}

}
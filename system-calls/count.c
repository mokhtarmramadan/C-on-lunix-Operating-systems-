// Q2- Write a program to print the count of characters read by the read() system call.


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

// Inatialize the max size of buff array 
const int max_size = 100;

int main()
{	char *buff [max_size];
	
	// Read characters till we reach the max_size
	int bytes_read = read(0, buff, max_size);
	
	// Print the count
	printf("You've entered %d characters\n", (bytes_read - 1));

}
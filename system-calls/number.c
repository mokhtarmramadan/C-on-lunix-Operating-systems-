// Q7- Write a program to read a number(n) from the user, print the first n characters from the file F1.txt.





#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdlib.h>





int main()
{	
	// The ASCII value of the user input
	int number;
	
	// Read users input through stdin sys call 
	read(0, &number, 1);

	// Convert the number user entered from ASCII to integer 
	int number_of_bytes = number - 48;
	
	// Create a buffer array with the number provided as an index 
	int buff[number];
	
	// Open the file in Read and Write mode
	int file = open("file.txt", O_RDWR);
	
	// Read number_of_bytes from file to buff
	read(file, buff, number_of_bytes);
	
	// Write number_of_bytes from buff to the terminal through stdout sys call
	write(1, buff, number_of_bytes);

}
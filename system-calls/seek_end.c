// Q6- Write a program to print the last 5 character of a file.


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>




int main()
{	char buff [5];

	// Open the first file in read mode	
	int file = open("file.txt", O_RDONLY);
	
	// Move the pointer to -6 character from the end
	lseek(file, -6, SEEK_END);
	
	// Read characters till we reach the max_size
	int bytes_read = read(file, buff, 5);
	
	// Write what's in buff into the file
	write(1, buff, bytes_read);
	
	// Close the file descriptors 
	close(file);

}
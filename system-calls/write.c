// Q4- Write a program using open() system call to copy the contents of one file into another file.


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>




int main()
{	char buff [100];

	// Open the first file in read mode	
	int file = open("file.txt", O_RDONLY);
	
	// print the file descriptor to make sure that the file opens successfully
	printf("The file descriptor is %d\n", file);
	
	// Read characters till we reach the max_size
	int bytes_read = read(file, buff, 99);
	
	// Open the file that we'll write into in write mode
	int new_file = open("new_file.txt", O_WRONLY);
	
	// Write what's in buff into the file
	write(new_file, buff, bytes_read);
	
	// Close the file descriptors 
  	close(new_file);
	close(file);

}
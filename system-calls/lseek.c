// Q5- Write a program to print characters starting from 15th character till the 20th character of file F1.txt to file F4.txt.


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>




int main()
{	char buff [5];

	// Open the first file in read mode	
	int file = open("file.txt", O_RDONLY);
	
	// Move the pointer to character number 15
	lseek(file, 15, SEEK_SET);
	
	// Read characters till we reach the max_size
	int bytes_read = read(file, buff, 5);
	
	// Open the file that we'll write into in create mode
	int new_file = open("new_file.txt", O_WRONLY|O_CREAT, 0642);
	
	// Write what's in buff into the file
	write(new_file, buff, bytes_read);
	
	// Close the file descriptors 
  	close(new_file);
	close(file);

}
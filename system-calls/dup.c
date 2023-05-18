// Q8 - Write a program to duplicate a file descriptor of a file use the old file descriptor to read the first 5 characters and the new file descriptor to append some new content to the file. 





#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>




int main()
{	
	// Buffer array
	int buff[5];
	
	// Inatialize file descriptor and open the file in read, write and append mode
	int file = open("file.txt", O_RDWR|O_APPEND);
	
	// Read the first 5 Characters and write them (stdout)
	read(file, buff, 5);
	write(1, buff, 5);
	
	// Inatialize a new file descriptor by dup() and append to it the buff content
	int new_file_descriptor = dup(file);
	write(new_file_descriptor, buff, 5);		
	

}
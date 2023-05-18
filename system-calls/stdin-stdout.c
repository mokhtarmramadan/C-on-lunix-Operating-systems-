// Q1- Write a program to read a maximum of 15 characters from the user and print them on the screen.


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    // An array of strings to buffer into
    char *buff[15];

    // Read max 15 char into buff array
    int bytes_read = read(0, buff, 15);
    // Write all the bytes the user provided (less than 15)
    write(1, buff, bytes_read);

}
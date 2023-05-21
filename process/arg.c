#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

struct student {
    char *name;
    int age;
};


void *thread_one(void *arg)
{
    struct student *p = (struct student *)arg;
   printf("Studnet name : %s\n", p->name);
   printf("Studnet age : %d\n", p->age);
    
}



int main(void)
{

    // Inatialize, create T1, T2 threads and wait for them to finish
    pthread_t T1;
    
    struct student Ahmed;
    Ahmed.name = "Ahmed";
    Ahmed.age = 19;
    
    

    pthread_create(&T1, NULL, thread_one, (void *) &Ahmed);    
    pthread_join(T1, NULL);

    
}
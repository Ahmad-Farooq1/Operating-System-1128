// Question 1/1
// Write a C program that demonstrates and fixes a race condition:
// 1.    Create a shared global variable                   initialized to 0
// 2.  Create 3 threads, each thread increments
// 3.  First version WITHOUT mutex:
//   Create and run the 3 threads
// 1000 times in a loop
//   Print the final counter value
//   Run multiple times and observe inconsistent results
// 4.  Second version WITH mutex:
//   Use mutex to protect the counter increment   Create and run the 3 threads
//    Print the final counter value (should always be 3000)
// Requirements:
//    Show both versions (with and without mutex) Add comments explaining why mutex is needed Properly initialize and destroy mutex


// NAME: Ahmad Farooq
// RollNo: 23-NTU-CS-1128
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>  //here i include all the required libraries which will in use

int counter = 0;     //the counter is a shared global variable that can be used for race consition
#define NUM_THREADS 3  //here are the total number of threads
#define INCREMENTS 100000 //increments is a constant which will be used tot tell total npo of increments in the function 
pthread_mutex_t mutex; //object of pthread_mutex is created

//THis function increments the counter without using mutex
void* incrementWithout_mutex(void* arg){
    for(int i = 0; i < INCREMENTS; i++){
        counter++;
    }
    return NULL;
}
// This function using mutex to lock a thread and not allowing other threads to interupt that 
void* incrementWith_mutex(void* arg){
    for(int i=0; i<INCREMENTS; i++){
        pthread_mutex_lock(&mutex);  // mutex lock for preventing Race Condition
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main(){
    pthread_t threads[NUM_THREADS];
    counter =0;
    // for (int i=0; i<NUM_THREADS; i++){
    //     pthread_create(&threads[i],NULL,incrementWithout_mutex,NULL);
    // }
    // pthread create creates thread 
        pthread_create(&threads[0],NULL,incrementWithout_mutex,NULL);
        pthread_create(&threads[1],NULL,incrementWithout_mutex,NULL);
        pthread_create(&threads[2],NULL,incrementWithout_mutex,NULL);
// pthread join waits for the thread completion which is created
    for (int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i],NULL);   
    }
    printf("counter without using the mutex: %d\n",counter);
    counter =0;
    // counter again set to 0
    pthread_mutex_init(&mutex,NULL);
    for (int i=0; i<NUM_THREADS; i++){
        pthread_create(&threads[i],NULL,incrementWith_mutex,NULL);
    }
    for (int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i],NULL);
        }
printf("counter with using the mutex: %d\n",counter);
// mutex destoryed after using it
pthread_mutex_destroy(&mutex);
return 0;
}

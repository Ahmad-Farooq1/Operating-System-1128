// Name: Ahmad Farooq
// Rollno: 23-NTU-CS-1128
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5
void* thread_func(void* arg) {
    int thread_num = *(int*)arg;
    pthread_t tid = pthread_self(); // pthread_self is used to get thread id
    printf("Thread %d started. Thread ID: %lu\n", thread_num, tid);
    int sleep_time = rand() % 3 + 1; // Built in rand() function is used to get ransom number
    sleep(sleep_time);
    printf("Thread %d completed after %d seconds.\n", thread_num, sleep_time);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];
    srand(time(NULL)); // seed for random number is current time to not get a pattern of numbers
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_nums[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_func, &thread_nums[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads have finished.\n");
    return 0;
}

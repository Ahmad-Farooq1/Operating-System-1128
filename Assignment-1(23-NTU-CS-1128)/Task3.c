// Name: Ahmad Farooq
// Rollno: 23-NTU-CS-1128
#include <stdio.h>
#include <pthread.h>

void* number_info(void* arg) {
    int num = *(int*)arg;
    printf("Thread: Number = %d\n", num);
    printf("Thread: Square = %d\n", num * num);
    printf("Thread: Cube = %d\n", num * num * num);
    return NULL;
}
int main() {
    pthread_t thread;
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    pthread_create(&thread, NULL, number_info, &num);
    pthread_join(thread, NULL);

    printf("Main thread: Work completed.\n");
    return 0;
}

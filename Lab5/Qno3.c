// Passing Multiple Data
#include <stdio.h>
#include <pthread.h>
typedef struct {
int id;
char* message;
float number;
} ThreadData;
void* printData(void* arg) {
ThreadData* data = (ThreadData*)arg;
printf(" %s %.2f\n" , data->message,data->number);
return NULL;
}
int main() {
pthread_t t1;
ThreadData data1 = {1, "I am Ahmad Farooq and my cgpa is: ",3.23};
pthread_create(&t1, NULL, printData, &data1);
pthread_join(t1, NULL);
return 0;
}
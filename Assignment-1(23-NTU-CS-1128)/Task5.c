// Name: Ahmad Farooq
// Rollno: 23-NTU-CS-1128
#include <stdio.h>
#include <pthread.h>

typedef struct {
    int student_id;
    char name[50];
    float gpa;
} Student;

int d_count = 0; // Shared variable critical part
pthread_mutex_t lock; // mutex lock to prevent race condition

void* student_info(void* arg) {
    Student* s = (Student*)arg;

    printf("\nStudent ID: %d\nName: %s\nGPA: %.2f\n", s->student_id, s->name, s->gpa);

    if (s->gpa >= 3.5) {
        printf("Status: Eligible for Dean's List!\n");
        pthread_mutex_lock(&lock);
        d_count++;
        pthread_mutex_unlock(&lock);
    } else {
        printf("Status: Not eligible for Dean's List.\n");
    }
    return NULL;
}

int main() {
    pthread_t threads[4];
    pthread_mutex_init(&lock, NULL);

    Student students[4] = {
        {1128, "Ahmad Farooq", 3.18},
        {1130, "Ahsan", 3.2},
        {1123, "Rana G", 4.5},
        {1160, "Hadi", 10}
    };

    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, student_info, &students[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nTotal students on Dean's List: %d\n", d_count);

    pthread_mutex_destroy(&lock);
    return 0;
}

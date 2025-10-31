// Name: Ahmad Farooq
// Rollno: 23-NTU-CS-1128
#include <stdio.h>
#include <pthread.h>

long long result = 1; // Global variable to store factorial result

void* factorial(void* arg) {
    int n = *(int*)arg; // Get the number from main thread

    for (int i = 1; i <= n; i++) {
        result *= i; // Calculate factorial
    }

    pthread_exit(NULL); // No need to return anything
}

int main() {
    pthread_t thread;
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    pthread_create(&thread, NULL, factorial, &n); // Start thread
    pthread_join(thread, NULL); // Wait for thread to finish

    printf("Factorial of %d is %lld\n", n, result);

    return 0;
}

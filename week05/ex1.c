#include <stdio.h>
#include <pthread.h>

void *threadJob(void *argp) {
    printf("\tThread number %d\n", *(int *) argp);

    pthread_exit(0);
    return 0;
}

int main() {
    int N = 10;
    pthread_t threads[N];
    printf("Parallel: \n");
    for (int i = 1; i <= N; ++i) {
        printf("Thread %d start\n", i);
        int iArg = i;
        pthread_create(&threads[i], 0, threadJob, &iArg);
        printf("Thread %d end\n", i);
    }

    printf("\nSequential: \n");
    for (int i = 1; i <= N; ++i) {
        printf("Thread %d start\n", i);
        int iArg = i;
        pthread_create(&threads[i], 0, threadJob, &iArg);
        pthread_join(threads[i], 0); // Fix here
        printf("Thread %d end\n", i);
    }

    return 0;
}
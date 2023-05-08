#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t mutex, wrt;
int a = 10, readcount = 0;
void *reader(void *arg) {
    long int num = (long int)arg;
    while (1) {
        sem_wait(&mutex);
        readcount++;
        if (readcount == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mutex);
        printf("Reader %li is in critical section\n", num);
        printf("Reader %li is reading data %d\n", num, a);
        sleep(1);
        sem_wait(&mutex);
        readcount--;
        if (readcount == 0) {
            sem_post(&wrt);
        }
        sem_post(&mutex);
        printf("Reader %li left critical section\n", num);
        sleep(rand() % 3 + 1); // Sleep for random time before trying again
    }
}

void *writer(void *arg) {
    long int num = (long int)arg;
    while (1) {
        sem_wait(&wrt);
        printf("Writer %li is in critical section\n", num);
        printf("Writer %li have written data as %d\n", num, ++a);
        sleep(1);
        sem_post(&wrt);
        printf("Writer %li left critical section\n", num);
        sleep(rand() % 3 + 1); // Sleep for random time before trying again
    }
}
sem_init(&mutex, 0, 1);
sem_init(&wrt, 0, 1);
int main() {
    pthread_t r[10], w[10];
    long int i, j;
    int nor, now;
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    printf("Enter number of readers and writers: ");
    scanf("%d %d", &nor, &now);

    for (i = 0; i < nor; i++) {
        pthread_create(&r[i], NULL, reader, (void *)i);
    }

    for (j = 0; j < now; j++) {
        pthread_create(&w[j], NULL, writer, (void *)j);
    }

    for (i = 0; i < nor; i++) {
        pthread_join(r[i], NULL);
    }

    for (j = 0; j < now; j++) {
        pthread_join(w[j], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
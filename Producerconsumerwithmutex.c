#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0;

pthread_mutex_t mutex;

void *producer(void *arg) {
    int item = 0;

    while (1) {
        item = rand() % 100 + 1;

        pthread_mutex_lock(&mutex);

        if (count < BUFFER_SIZE) {
            buffer[count] = item;
            count++;
            printf("Produced item: %d\n", item);
        }

        pthread_mutex_unlock(&mutex);

        sleep(rand() % 3 + 1);
    }
}

void *consumer(void *arg) {
    int item = 0;

    while (1) {
        pthread_mutex_lock(&mutex);

        if (count > 0) {
            item = buffer[count - 1];
            count--;
            printf("Consumed item: %d\n", item);
        }

        pthread_mutex_unlock(&mutex);

        sleep(rand() % 3 + 1);
    }
}

int main() {
    pthread_t prod, cons;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}
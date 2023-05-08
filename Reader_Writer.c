#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> pthread_mutex_t wr,mutex;
int a = 10, readcount = 0;
void *reader(void *arg)
{
    long int num;
    num = (long int)arg;
    pthread_mutex_lock(&mutex);
    readcount++;
    pthread_mutex_unlock(&mutex);
    if (readcount == 1)
        pthread_mutex_lock(&wr);
    printf("\n Reader %li is in critical section", num);
    printf("\n Reader %li is reading data %d", num, a);
    sleep(1);
    pthread_mutex_lock(&mutex);
    readcount--;
    pthread_mutex_unlock(&mutex);
    if (readcount == 0)
        pthread_mutex_unlock(&wr);
    printf("\n Reader %li left critical section", num);
}
void *writer(void *arg)
{
    long int num;
    num = (long int)arg;
    pthread_mutex_lock(&wr);
    printf("\n Writer %li is in left critical section", num);
    printf("\n Writer %li have written data as %d ", num, ++a);
    sleep(1);
    pthread_mutex_unlock(&wr);
    printf("\n Writer %li left critical section", num);
}
int main()
{
    pthread_t r[10], w[10];
    long int i, j;
    int nor, now;
    pthread_mutex_init(&wr, NULL);
    pthread_mutex_init(&mutex, NULL);
    printf("Mandar Gatke's code:\n");
    printf("Enter number of reader and writers\n");
    scanf("%d %d", &nor, &now);
    for (i = 0; i < nor; i++)
    {
        pthread_create(&r[i], NULL, reader, (void *)i);
    }
    for (j = 0; j < now; j++)
    {
        pthread_create(&w[j], NULL, writer, (void *)j);
    }
    for (i = 0; i < nor; i++)
    {
        pthread_join(r[i], NULL);
    }
    for (j = 0; j < now; j++)
    {
        pthread_join(w[j], NULL);
    }
    return 0;
}

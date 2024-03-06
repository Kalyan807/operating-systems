#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t rw_mutex, mutex;
int read_count = 0;

void *reader(void *arg) {
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1)
        sem_wait(&rw_mutex);
    sem_post(&mutex);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0)
        sem_post(&rw_mutex);
    sem_post(&mutex);

    pthread_exit(NULL);
}

void *writer(void *arg) {
    sem_wait(&rw_mutex);


    sem_post(&rw_mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t r1, r2, w1, w2;

    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_create(&w2, NULL, writer, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);
    pthread_join(w2, NULL);

    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    return 0;
}

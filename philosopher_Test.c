#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t* mutexes;
int num_threads;

void* thread_function(void* arg) {
    int thread_num = *(int*)arg;
    free(arg);

    // Bloquear el mutex correspondiente al hilo
    pthread_mutex_lock(&mutexes[thread_num]);
    // Bloquear el mutex n+1, y el primero si el hilo es el último
    pthread_mutex_lock(&mutexes[(thread_num + 1) % num_threads]);

    // Sección crítica
    printf("Thread %d is running\n", thread_num);
    usleep(2000000); // Dormir durante 2 segundos (2,000,000 microsegundos)

    // Desbloquear el mutex correspondiente al hilo
    pthread_mutex_unlock(&mutexes[thread_num]);
    // Bloquear el mutex n+1, y el primero si el hilo es el último
    pthread_mutex_unlock(&mutexes[(thread_num + 1) % num_threads]);


    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    num_threads = atoi(argv[1]);
    if (num_threads <= 0) {
        fprintf(stderr, "Number of threads must be positive\n");
        return 1;
    }

    pthread_t* threads = malloc(num_threads * sizeof(pthread_t));
    mutexes = malloc(num_threads * sizeof(pthread_mutex_t));

    // Inicializar los mutexes
    for (int i = 0; i < num_threads; i++) {
        pthread_mutex_init(&mutexes[i], NULL);
    }

    // Crear los hilos
    for (int i = 0; i < num_threads; i++) {
        int* thread_num = malloc(sizeof(int));
        *thread_num = i;
        pthread_create(&threads[i], NULL, thread_function, thread_num);
    }

    // Esperar a que los hilos terminen
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destruir los mutexes
    for (int i = 0; i < num_threads; i++) {
        pthread_mutex_destroy(&mutexes[i]);
    }

    free(threads);
    free(mutexes);

    return 0;
}
